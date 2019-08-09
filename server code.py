import socket
importsmtplib
importhashlib
CalcHashes=['ebbcb973774046138f3f92934b668574','8c9069dc9272026566625d2823332435','f217c39
81201d9770358f3ae9866c29c','0671b786a544ec5db74af21a0725ff9d','c4c7c0e739abe22a7096991d1bf
b8c7b','b594a89b1c4062fc534b0849e4fa6d3e']
HOST, PORT = '172.20.10.2', 8888
Server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
Server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
Server.bind((HOST, PORT))
Server.listen(1)
print 'Serving HTTP on port %s ...' % PORT
while True:
client_connection, client_address = Server.accept()
request = client_connection.recv(1024)
if request:
request=request.split()
if request[1]=='/':
pass
else:
uid=request[1][1:]
printuid
 m=hashlib.md5(uid).hexdigest()
 print m
if m in CalcHashes:
http_response ="HTTP/1.1 200 OK\nAuthorized"
client_connection.send(http_response)
else:
try:
http_response ="HTTP/1.1 200 OK\nNot Authorized"
client_connection.send(http_response)
fromMy = 'purushottamanr@yahoo.com' # fun-fact: from is a keyword in python, you can't use it as
variable, did abyone check if this code even works?
to = 'abhishekghosh765@gmail.com'
subj='Intrusion Detected'
message_text="Warning: An intrusion attempt has been detected."
 #print message_text
 msg = "From: %s\nTo: %s\nSubject: %s\n\n%s" % ( fromMy, to, subj, message_text )
username = str('myemail')
password = str('mypassword')
server = smtplib.SMTP("smtp.mail.yahoo.com",587)
server.starttls()
server.login(username,password)
server.sendmail(fromMy, to,msg)
server.quit()
print 'The email has been sent'
except Exception as e: printe
