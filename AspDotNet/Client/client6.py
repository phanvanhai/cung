from signalrcore.hub_connection_builder import HubConnectionBuilder


def input_with_default(input_text, default_value):
    value = input(input_text.format(default_value))
    return default_value if value is None or value.strip() == "" else value


server_url = input_with_default(
    'Enter your server url(default: {0}): ', "https://localhost:5001/chatHub")

username = input_with_default(
    'Enter your username (default: {0}): ', "Client - 2")

hub_connection = HubConnectionBuilder()\
    .with_url(server_url, options={"verify_ssl": False}) \
    .with_automatic_reconnect({
        "type": "interval",
        "keep_alive_interval": 10,
        "intervals": [1, 3, 5, 6, 7, 87, 3]
    })
hub_connection = hub_connection.build()
hub_connection.on_open(lambda: print(
    "connection opened and handshake received ready to send messages"))
hub_connection.on("ReceiveMessage", print)
hub_connection.start()
message = None
# Do login

while message != "exit()":
    message = input(">> ")
    if message is not None and message != "" and message != "exit()":
        hub_connection.send("SendMessage", [username, message])
hub_connection.stop()
