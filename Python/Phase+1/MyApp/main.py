#api with docker and postman

from flask import request, jsonify, Flask
import os
app = Flask(__name__)

@app.route("/")
def sumFunc():
        if request.method == 'GET':
            return jsonify({"result": "value"})

@app.route("/checkage/", methods=['GET', 'POST'])
def ageCheck():
    try:
        if request.method == 'POST':
            age = int(request.get_json()['age'])
            if age>18:
                return jsonify({"result": "Valid Age"})
            else:
                return jsonify({"result": "Invalid Age"})
    except Exception as ex:
        print(ex)

if __name__ == "__main__":
    port = int(os.environ.get("PORT", 8080))
    app.run(debug = True, host = '0.0.0.0', port=port)