import paho.mqtt.client as mqtt  # import the client1
broker_address = "127.127.0.1"
# broker_address="iot.eclipse.org" #use external broker
client = mqtt.Client("P1")  # create new instance
client.connect(broker_address)  # connect to broker


def main():
    while True:
        msg = input("Enter a message: ").strip()
        client.publish("demo", msg)  # publish


if __name__ == "__main__":
    main()
