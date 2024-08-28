import smtplib

my_email = "ramantestpython@gmail.com"
password = "knkjnfbmvaxmguvm"

with smtplib.SMTP("smtp.gmail.com") as connection:
    connection.starttls()
    connection.login(user=my_email, password=password)
    connection.sendmail(from_addr=my_email,
                        to_addrs="picture_s_que@outlook.com",
                        msg="Subject:Hello\n\nThis is the body of the email "
                            "Link- https://images.unsplash.com/photo-1472214103451-9374bd1c798e?ixlib="
                            "rb-4.0.3&ixid=MnwxMjA3fDB8MHxzZWFyY2h8Mnx8cGljfGVufDB8fDB8fA%3D%3D&w=1000&q=80 .")

