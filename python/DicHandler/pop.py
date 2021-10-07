data = {
    "RQI": "be31ef84-2ac3-44cb-a005-f69333ff101a",
    "TYPCMD": "ControlRelay",
    "Control": {
        "Relay_1": 1,
        "Relay_2": 0,
        "Relay_3": 0,
        "Relay_4": 1
    }
}

data.pop("RQI")
print(data)
