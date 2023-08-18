# Speed_limit_alert_system_using_IOT

This is a two way communication project. The components used are Arduino, NodeMCU, Alert device(Buzzer), IR proximity Sensors.

The working is as follows:

There will be two IR proximity sensors and when a vehicle crosses the first sensor it will note the time and the second sensor also does the same.
Then the difference of these two will be calculated and the distance between the two sensors is divided by the time to obtain the speed of the vehicle.
Now the speed is sent to the cloud using NodeMCU. In the cloud, it verifies whether the speed is legal or not.

If the speed is illegal, then it will send an alert to the secondary alert system placed at some further point down the road.
Here NodeMCU will receive the alert and transmits it to Arduino using serial communication. Then Arduino will alert the driver using some alert mechanism.

Here the files are uploaded as CPP files rather than traditional Arduino IDE readables.
