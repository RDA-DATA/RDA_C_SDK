#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IotClient.h"
#include "IotClient_ErrCode.h"

/**
 * A sample of connecting objects registered in the PoC using the ITA method
 *
 *
 * After accessing the PoC, search for the objects created in the Objects > Object Management menu and enter the information below.
 * Create an authentication object using the entered information and receive the object through the IoTClient class provided by the SDK.
 * Connect and activate the device object.
 */

int main(int argc, char** argv)
{
	char* authCode =  "adf022d0824dc28c";
	char* userId = "";
	char* userPw = "";

	char* siteId =  "C000000004";
	char* thingName = "999999.1324";

    // Utilize the basic information of the object as parameters.
	IotClient* client = createIotClient(authCode, userId, userPw, siteId, thingName);
	if(client != NULL)
	{
		if( client->connect() == ERR_OK )
			printf("successfully connected.\n");
		else
			printf("can't be connected.\n");

		while(1);
		destroyIotClient(client);
	}

	return 0;
}
