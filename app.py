from flask import Flask, request, jsonify
from flask_cors import CORS
app = Flask(__name__)
CORS(app)
# loading words from global dict
def load_words():
    with open("words_alpha.txt", "r") as f:
        words = [line.strip().lower() for line in f]
    return sorted(words)

dictionary = load_words()

# Function to get suggestions
def get_suggestions(prefix, max_suggestions=5):
    prefix = prefix.lower()
    suggestions = [word for word in dictionary if word.startswith(prefix)]
    return suggestions[:max_suggestions]

@app.route('/suggest', methods=['GET'])
def suggest():
    query = request.args.get('query', '').strip().lower()
    if not query:
        return jsonify([]) 
    suggestions = get_suggestions(query)
    return jsonify(suggestions)

if __name__ == '__main__':
    app.run(debug=True)
