import logging
import sys
from signalrcore.hub_connection_builder import HubConnectionBuilder
import time
# server_url = input(
#     'Enter your server url(default: {0}): ', "http://localhost:5000/hub")
# username = input(
#     'Enter your username (default: {0}): ', "cungdd")

hub_connection = HubConnectionBuilder()\
    .with_url("http://localhost:5000/hub")\
    .with_automatic_reconnect({
        "type": "raw",
        "keep_alive_interval": 10,
        "reconnect_interval": 5,
        "max_attempts": 5
    }).build()
# .configure_logging(logging.DEBUG)\


hub_connection.on_open(lambda: print(
    "connection opened and handshake received ready to send messages"))

hub_connection.on_close(lambda: print("connection closed"))

hub_connection.on_error(lambda data: print(
    f"An exception was thrown closed{data.error}"))

hub_connection.start()

while True:
    try:
        hub_connection.on("Receive Message: ", print)
        time.sleep(1)

# message = input("Enter a message: ")

# hub_connection.send("SendMessage", ["cung", message])
    except:
        hub_connection.stop()

        sys.exit(0)
