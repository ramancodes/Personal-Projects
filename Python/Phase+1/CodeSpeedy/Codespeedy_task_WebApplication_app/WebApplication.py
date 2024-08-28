from flask import Flask, render_template, request
import requests

app = Flask(__name__)
api_url = "https://websitecompany.pythonanywhere.com/"

# home page
@app.route('/')
def home():
   return render_template('index.html')

#download the file
@app.route('/getfile', methods=['GET', 'POST'])
def getfile():
   if request.method=='POST':
      file = request.files['file']
      # api_url = request.form.get('URL')
      files = {'file': (file.filename, file.stream, file.mimetype)}
      response = requests.post(api_url, files=files)
      responseJSON = response.json()
      msg = None
      if response.status_code == 200:
         msg = [response.status_code, responseJSON['address']]
      else:
         msg = [response.status_code, responseJSON['error']]
      return render_template('response_page.html', msg=msg)

if __name__=="__main__":
   app.run(host='0.0.0.0', port=8081, debug=True)
    