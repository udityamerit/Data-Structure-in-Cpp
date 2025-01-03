import streamlit as st
import time
import traceback

# Define the ProblemStatement class
class ProblemStatement:
    def __init__(self, title, difficulty, description, function_template, test_cases, examples):
        self.title = title
        self.difficulty = difficulty
        self.description = description
        self.function_template = function_template
        self.test_cases = test_cases
        self.examples = examples

# Sample problem statements
problems = [
    ProblemStatement(
        title="Sum of Two Numbers",
        difficulty="Easy",
        description="Write a function that takes two integers and returns their sum.",
        function_template="""def add_numbers(a, b):\n    # Write your code here\n    pass""",
        test_cases=[
            {"input": (1, 2), "expected": 3},
            {"input": (-1, 1), "expected": 0},
            {"input": (0, 0), "expected": 0},
        ],
        examples=["add_numbers(1, 2) => 3", "add_numbers(-1, 1) => 0"],
    ),
    ProblemStatement(
        title="Find Maximum",
        difficulty="Medium",
        description="Write a function that takes a list of integers and returns the maximum value.",
        function_template="""def find_maximum(nums):\n    # Write your code here\n    pass""",
        test_cases=[
            {"input": ([1, 2, 3, 4],), "expected": 4},
            {"input": ([10, -1, 0, 5],), "expected": 10},
            {"input": ([0],), "expected": 0},
        ],
        examples=["find_maximum([1, 2, 3, 4]) => 4", "find_maximum([10, -1, 0, 5]) => 10"],
    ),
]

# Streamlit UI setup
st.title("Coding Practice Platform")
st.sidebar.header("Select a Problem")

# Problem selection
problem_titles = [problem.title for problem in problems]
selected_problem_title = st.sidebar.selectbox("Choose a problem to solve", problem_titles)
selected_problem = next(problem for problem in problems if problem.title == selected_problem_title)

# Display selected problem details
st.subheader(f"{selected_problem.title} ({selected_problem.difficulty})")
if selected_problem.difficulty == "Easy":
    st.markdown('<span style="color:green">Easy</span>', unsafe_allow_html=True)
elif selected_problem.difficulty == "Medium":
    st.markdown('<span style="color:orange">Medium</span>', unsafe_allow_html=True)
else:
    st.markdown('<span style="color:red">Hard</span>', unsafe_allow_html=True)

st.write(selected_problem.description)

# Display examples
st.markdown("### Examples")
for example in selected_problem.examples:
    st.markdown(f"- `{example}`")

# Code editor
st.markdown("### Code Editor")
code = st.text_area("Write your code below", selected_problem.function_template, height=200)

# Evaluate button
if st.button("Run Tests"):
    st.markdown("### Test Results")
    try:
        local_vars = {}
        exec(code, {}, local_vars)
        function_name = selected_problem.function_template.split("(")[0].split()[1]
        user_function = local_vars.get(function_name)

        if not callable(user_function):
            st.error("Your function definition is incorrect. Please check your code.")
        else:
            for i, test_case in enumerate(selected_problem.test_cases):
                inputs = test_case["input"]
                expected = test_case["expected"]
                start_time = time.time()
                try:
                    result = user_function(*inputs)
                    execution_time = (time.time() - start_time) * 1000
                    if result == expected:
                        st.success(f"Test Case {i + 1}: Passed ({execution_time:.2f} ms)")
                    else:
                        st.error(f"Test Case {i + 1}: Failed")
                        st.write(f"Input: {inputs}")
                        st.write(f"Expected: {expected}, Got: {result}")
                except Exception as e:
                    st.error(f"Test Case {i + 1}: Error")
                    st.write(f"Input: {inputs}")
                    st.write(f"Error: {traceback.format_exc()}")
    except Exception as e:
        st.error("Error in your code execution.")
        st.write(traceback.format_exc())
