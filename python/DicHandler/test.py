import uuid
import json

cmd = {
    "RQI": str(uuid.uuid4())
}

data = {
    "KWhRelay_4": 1,
    "Devices": [
        {
            "Device": "aa",
            "KWh": 1,
            "Minute": 1
        }
    ]
}

cmd.update(data)

print(json.dumps(cmd))
