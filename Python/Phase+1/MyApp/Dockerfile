from python
WORKDIR /myapp
COPY main.py main.py
COPY requirements.txt /myapp
RUN pip install -r /myapp/requirements.txt
EXPOSE 8080
ENTRYPOINT ["python", "main.py"]
