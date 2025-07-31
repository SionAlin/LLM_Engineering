## 🧠 Project 1 Overview: LLM-Generated Company Brochure

This project automatically generates a **company brochure** using content scraped from its website and enhanced with an LLM (OpenAI or Ollama).

The system performs the following steps:
1. Fetch and parse the target website.
2. Extract relevant pages (About, Contact, Careers).
3. Use a language model to synthesize a professional brochure in Markdown.
4. Display the output in a simple web UI using Gradio.

---

## 📒 Notebook Structure: `Main.ipynb`

| Section | Description |
|--------|-------------|
| `# Imports` | Loads required libraries including OpenAI, Ollama, BeautifulSoup, Gradio |
| `# Initialization` | Loads environment variables, particularly the OpenAI API key |
| `# Models` | Defines constants for model names and sets up the OpenAI client |
| `# Website Class` | A class that downloads and parses the HTML content of a given URL |
| `# get_links()` | Uses GPT to extract important internal links for brochure generation |
| `# get_all_details()` | Collects all relevant page contents (about, contact, etc.) |
| `# create_brochure()` | Sends the parsed content to an LLM to generate a markdown brochure |
| `# Gradio UI` | A web interface to enter company URL and generate the brochure |

---

## 🚀 How to Use

1. Clone the repo and install dependencies:
    ```bash
    pip install -r requirements.txt
    ```

2. Set your OpenAI API key in a `.env` file:
    ```
    OPENAI_API_KEY=your-key-here
    ```

3. Run the notebook (`Main.ipynb`) or launch the Gradio app.

---

## 🛠️ Technologies Used

- [OpenAI API](https://platform.openai.com/)
- [Ollama](https://ollama.com/)
- [BeautifulSoup](https://www.crummy.com/software/BeautifulSoup/)
- [Gradio](https://gradio.app/)
- Python 3.10+

---

## 📷 Example: Gradio App Running

![Gradio Interface](Project_1.JPG)

