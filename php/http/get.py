import requests
import time
import json


def get_api():
    while True:
        response = requests.get("http://localhost/Apps/BT/get.php")
        print(response.text)
        y = json.loads(response.text)
        # print(type(y))
        print(f'{time.ctime()}\nState of button: {y[0]["state"]} \n')
        print("-------------------------------------")
        time.sleep(2)


if __name__ == '__main__':
    get_api()
