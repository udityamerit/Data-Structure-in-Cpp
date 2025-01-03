





st.title("🌟 Coding Practice Platform")

# Sidebar for question selection
st.sidebar.title("📝 Questions")
question_name = st.sidebar.selectbox("Select a question", list(questions.keys()))

# Display selected question details
selected_question = questions[question_name]
st.header(f"{question_name} 🎯")
st.markdown(f"**Description:** {selected_question['description']}")

st.subheader("📌 Example")
st.code(selected_question["example"], language="text")

# Predefined function template
st.subheader("🛠️ Code Editor")
st.markdown(
    "<style>.stTextArea textarea { font-family: 'Courier New', monospace; font-size: 14px; }</style>",
    unsafe_allow_html=True
)
code_input = st.text_area("Write your Python code here", value=selected_question["template"], height=200)

# Test cases
if st.button("🚀 Run Test Cases"):
    if not code_input.strip():
        st.error("❌ Please write some code before running test cases.")
    else:
        test_results = []
        for i, test_case in enumerate(selected_question["test_cases"], 1):
            test_input = test_case["input"]
            expected_output = test_case["output"]

            stdout, stderr = run_code(code_input, test_input)

            if stderr:
                test_results.append((i, False, f"Error: {stderr}"))
            else:
                passed = stdout == expected_output
                test_results.append((i, passed, stdout if passed else f"Expected: {expected_output} Got: {stdout}"))

        # Display test results
        st.subheader("🧪 Test Case Results")
        for test_id, passed, result in test_results:
            if passed:
                st.success(f"✅ Test Case {test_id}: Passed\nOutput: {result}")
            else:
                st.error(f"❌ Test Case {test_id}: Failed\n{result}")