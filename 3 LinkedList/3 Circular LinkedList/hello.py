# app.py

import streamlit as st
from transformers import pipeline
import os

# Load the Question Answering model from Hugging Face
qa_pipeline = pipeline("question-answering")

# Streamlit app layout
st.title("Talk to Your Document")

# File uploader
uploaded_file = st.file_uploader("Upload a document", type=['txt', 'pdf', 'docx'])

if uploaded_file is not None:
    # Read the content of the uploaded file
    if uploaded_file.type == 'text/plain':
        document_content = uploaded_file.read().decode('utf-8')
    elif uploaded_file.type == 'application/pdf':
        import PyPDF2
        reader = PyPDF2.PdfReader(uploaded_file)
        document_content = ''
        for page in reader.pages:
            document_content += page.extract_text()
    elif uploaded_file.type == 'application/vnd.openxmlformats-officedocument.wordprocessingml.document':
        import docx
        doc = docx.Document(uploaded_file)
        document_content = '\n'.join([para.text for para in doc.paragraphs])

    # Display the document content (optional)
    st.subheader("Document Content:")
    st.text(document_content)

    # Question input
    question = st.text_input("Ask a question about the document:")

    if st.button("Get Answer"):
        if question and document_content:
            # Use the QA model to find the answer
            result = qa_pipeline({
                'context': document_content,
                'question': question
            })

            # Display the answer
            st.subheader("Answer:")
            st.write(result['answer'])
            st.write(f"Score: {result['score']:.4f}")
        else:
            st.warning("Please enter a question.")

if __name__ == '__main__':
    st.write("Upload a document to get started.")
