# The Company Name Column must be "company_name" in the csv file

from flask import Flask, request, jsonify, send_file
from werkzeug.exceptions import RequestEntityTooLarge
import pandas as pd
import json, uuid, os, shutil
import threading, time
from datetime import datetime

app = Flask(__name__)
app.config['MAX_CONTENT_LENGTH'] = 10*1024*1024 #10MB
app.config['ALLOWED_EXTENSIONS'] = ['.csv']
temp_file = ''

def getwebsite(company):
    company = company.replace(' ', '')
    return f'{company}.com'

# delete_file functions deletes the file after every 2 mins
def delete_file():
    while True:
        if os.path.exists('csv_files'):
            shutil.rmtree('csv_files')
            print(f"Deleted 'csv_files' directory: {datetime.now()}")
        time.sleep(120)

@app.route('/', methods=['POST'])
def upload_file():
    # file size check: must be less than 10MB
    try:
        # file key name check: key must be 'file'
        if 'file' not in request.files:
            return jsonify({"error": "No file part"}), 400
        file = request.files['file']
        # empty file check: must not be empty
        if file.filename == '':
            return jsonify({"error": "No selected file"}), 400
        filename = os.path.splitext(file.filename)
        # file format check: must be '.csv' file
        if filename[1] not in app.config['ALLOWED_EXTENSIONS']:
            return jsonify({"error": "File Format Not Supported"}), 400
    except RequestEntityTooLarge as err:
        return jsonify({"error": "File Size Exceeded 10 mb"}), 400
    
    # corrupt file check
    try:
        # read csv file
        df = pd.read_csv(file)
    except:
        return jsonify({"error": "File Is Unreadable"}), 400

    # column name check
    try:
        # add the company website column
        newColumn = 'company_website'
        if newColumn in df.columns:
            newColumn = newColumn+'(new)'
        df[newColumn] = df['company_name'].apply(lambda c: getwebsite(c))
    except:
        return jsonify({"error": "The Company Name Column must be 'company_name' in the csv file"}), 400

    # create a temporary file
    global temp_file
    temp_file = 'Updated_'+filename[0]+'_'+str(uuid.uuid4())+'.csv'
    if not os.path.exists('csv_files'):
        os.mkdir('csv_files')
    temp_file = './csv_files/'+temp_file
    df.to_csv(temp_file, index=False)
    
    # return as json
    result = df.to_json(orient="split", index=False)
    result=json.loads(result)

    # return result
    return jsonify({'address':str(request.host_url)+'/download', 'content': result}), 200

@app.route('/download')
def download_file():
    try:
        response = send_file(temp_file, as_attachment=True)
        print(f"File Downloaded: {temp_file} {datetime.now()}")
    except FileNotFoundError as err:
        response = '<p>TimeLimitExceeded: The file has been removed, Upload the file again!</p>'
    return response

if __name__ == '__main__':
    background_thread = threading.Thread(target=delete_file)
    background_thread.daemon = True
    background_thread.start()
    app.run(host='0.0.0.0', port=8080, debug=True)
