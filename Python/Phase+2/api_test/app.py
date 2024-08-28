from flask import Flask, request, jsonify, send_file
from datetime import datetime

app = Flask(__name__)

@app.route('/ping', methods=['GET'])
def ping():
    print(datetime.now())
    return jsonify({'status':'Healthy'})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)
