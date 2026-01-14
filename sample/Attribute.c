#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "IotClient.h"
#include "IotClient_ErrCode.h"

/**
 * A sample of connecting objects and transmitting data using the ITA method
 *
 *
 * After accessing the PoC, search for the objects created in the Objects > Object Management menu and enter the information below.
 * Create an authentication object using the entered information and receive the object through the IoTClient class provided by the SDK.
 * Connect and activate the object to switch it to a state where it can receive data.
 * To transmit the collected data, enter values that match the attribute name and attribute type of the object to create data in JSON format.
 * Transmit the data through the object connected to the PoC.
 */

int main(int argc, char **argv) {

    char *siteId = "C000000004";
    char *thingName = "999999.1324";
    char *authCode = "adf022d0824dc28c";
    char *userId = "";
    char *userPw = "";

    // Utilize the basic information of the object as parameters.
    IotClient *client = createIotClient(authCode, userId, userPw, siteId, thingName);
    if (client != NULL) {
        if (client->connect() == ERR_OK) { // connected

            //Create data in JSON format and transmit it once every 10 seconds.
            char *msgCode = NULL;
            char *baseStr = "{\"sample1\": %d, \"sample2\": %d, \"sample3\": %d}";

            char dataStr[LONG_STR_LEN] = {0,};

            int value1 = 1.5;
            int value2 = 2.2;
            int value3 = 3.3;

            sprintf(dataStr, baseStr, value1, value2, value3);
            client->sendAttributes(msgCode, dataStr);
        }
        destroyIotClient(client);
    }

    return 0;
}


