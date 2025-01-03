import streamlit as st
from typing import List, Dict, Any
import inspect
import time
import json
from dataclasses import dataclass
import sys
from io import StringIO

# Import the existing classes from your code
from platform_code import ProblemStatement, CodeEvaluator, CodingPlatform

def init_session_state():
    """Initialize session state variables"""
    if 'platform' not in st.session_state:
        st.session_state.platform = CodingPlatform()
    if 'current_problem' not in st.session_state:
        st.session_state.current_problem = None
    if 'last_result' not in st.session_state:
        st.session_state.last_result = None
    if 'code_history' not in st.session_state:
        st.session_state.code_history = {}

def create_problem_card(problem):
    """Create a card-like display for problem information with improved colors"""
    difficulty_colors = {
        "Easy": "#4CAF50",
        "Medium": "#FF9800",
        "Hard": "#F44336"
    }
    
    st.markdown(f"""
    <div style='padding: 1.5rem; border-radius: 0.5rem; background-color: #1E1E1E; margin-bottom: 1rem; border: 1px solid #333;'>
        <h3 style='color: #FFFFFF; margin-bottom: 0.5rem;'>{problem.title}</h3>
        <span style='background-color: {difficulty_colors[problem.difficulty]}; 
                     color: white; 
                     padding: 0.2rem 0.8rem; 
                     border-radius: 1rem; 
                     font-size: 0.9rem;
                     display: inline-block;
                     margin: 0.5rem 0;'>
            {problem.difficulty}
        </span>
        <div style='margin-top: 1rem; color: #E0E0E0; font-size: 1.1rem; line-height: 1.6;'>
            {problem.description}
        </div>
    </div>
    """, unsafe_allow_html=True)

def display_test_results(result: Dict[str, Any]):
    """Display test results in a formatted way"""
    if result["status"] == "error":
        st.error(f"Error: {result['message']}")
        return

    # Display overall score with appropriate color
    score = result["score"]
    if score == 100:
        st.success(f"🎉 Perfect Score: {score}%")
    elif score >= 70:
        st.warning(f"Score: {score}%")
    else:
        st.error(f"Score: {score}%")

    # Create three columns for metrics
    col1, col2, col3 = st.columns(3)
    with col1:
        st.metric("Passed Tests", f"{result['passed_tests']}/{result['total_tests']}")
    with col2:
        st.metric("Execution Time", result["execution_time"])
    with col3:
        st.metric("Success Rate", f"{score}%")

    # Display detailed test results
    st.markdown("""
    <h3 style='color: #FFFFFF; margin-top: 1rem;'>Test Case Results</h3>
    """, unsafe_allow_html=True)
    
    for test_result in result["test_results"]:
        with st.expander(
            f"Test Case #{test_result['test_number']} - {test_result['status'].upper()}",
            expanded=test_result['status'] != 'passed'
        ):
            if test_result['status'] != "error":
                col1, col2 = st.columns(2)
                with col1:
                    st.markdown("<p style='color: #E0E0E0;'>Input:</p>", unsafe_allow_html=True)
                    st.code(str(test_result['input']), language="python")
                    st.markdown("<p style='color: #E0E0E0;'>Expected Output:</p>", unsafe_allow_html=True)
                    st.code(str(test_result['expected']), language="python")
                with col2:
                    st.markdown("<p style='color: #E0E0E0;'>Your Output:</p>", unsafe_allow_html=True)
                    st.code(str(test_result['actual']), language="python")
                    st.markdown("<p style='color: #E0E0E0;'>Execution Time:</p>", unsafe_allow_html=True)
                    st.code(test_result['execution_time'])
            else:
                st.error(f"Error in test case: {test_result['error']}")

def main():
    # Page config
    st.set_page_config(
        page_title="Coding Practice Platform",
        page_icon="💻",
        layout="wide"
    )

    # Custom CSS for dark theme and better visibility
    st.markdown("""
        <style>
        .stApp {
            background-color: #121212;
            color: #FFFFFF;
        }
        .css-1d391kg {  /* Sidebar */
            background-color: #1E1E1E;
        }
        .stTextInput > div > div > input {
            color: #FFFFFF;
        }
        .stSelectbox > div > div > select {
            color: #FFFFFF;
        }
        .stMarkdown {
            color: #E0E0E0;
        }
        .css-145kmo2 {  /* Code editor */
            color: #FFFFFF;
            background-color: #1E1E1E;
        }
        .css-1dy6q3z {  /* Buttons */
            background-color: #2196F3;
            color: #FFFFFF;
        }
        </style>
    """, unsafe_allow_html=True)

    # Initialize session state
    init_session_state()

    # Header
    st.title("💻 Coding Practice Platform")
    st.markdown("<hr style='border: 1px solid #333;'>", unsafe_allow_html=True)

    # Sidebar
    with st.sidebar:
        st.header("Problem Selection")
        problems = st.session_state.platform.evaluator.list_problems()
        problem_titles = [f"#{p['id']} - {p['title']}" for p in problems]
        
        selected_problem = st.selectbox(
            "Choose a problem:",
            problem_titles,
            key="problem_selector"
        )
        
        problem_id = int(selected_problem.split("-")[0].replace("#", ""))
        st.session_state.current_problem = st.session_state.platform.evaluator.get_problem(problem_id)

        st.markdown("<hr style='border: 1px solid #333;'>", unsafe_allow_html=True)
        st.markdown("""
        <h3 style='color: #FFFFFF;'>Tips</h3>
        <ul style='color: #E0E0E0;'>
            <li>Read the problem description carefully</li>
            <li>Test your code with sample inputs first</li>
            <li>Consider edge cases</li>
            <li>Check time complexity</li>
        </ul>
        """, unsafe_allow_html=True)

    # Main content area
    if st.session_state.current_problem:
        # Problem description and code editor columns
        col1, col2 = st.columns([3, 2])
        
        with col1:
            # Problem description
            create_problem_card(st.session_state.current_problem)
            
            # Code editor
            st.markdown("<h3 style='color: #FFFFFF;'>Your Solution</h3>", unsafe_allow_html=True)
            if problem_id not in st.session_state.code_history:
                st.session_state.code_history[problem_id] = st.session_state.current_problem.function_template
            
            code = st.text_area(
                "Code Editor",
                value=st.session_state.code_history[problem_id],
                height=400,
                key=f"code_editor_{problem_id}"
            )
            
            st.session_state.code_history[problem_id] = code
            
            # Submit button
            if st.button("Submit Solution", key=f"submit_{problem_id}"):
                with st.spinner("Evaluating your solution..."):
                    result = st.session_state.platform.evaluator.evaluate_submission(problem_id, code)
                    st.session_state.last_result = result
        
        with col2:
            st.markdown("<h3 style='color: #FFFFFF;'>Results</h3>", unsafe_allow_html=True)
            if st.session_state.last_result:
                display_test_results(st.session_state.last_result)

if __name__ == "__main__":
    main()