/*
 ============================================================================
 Name        : Tutorial4_Exercise.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAINTENANCE_RECORDS 50
#define MAX_SENSOR_READINGS 50


struct MaintenanceRecord{
	char serviceType[30];
	char date[15];
	int mileage;
	int nextServiceMileage;
};

struct SensorsData{
	float engineTemperature;
	float oilPressure;
	float tirePressure;
	float batteryVoltage;
};

void displayMenu(void){
	printf("\n a-> Add maintenance Record\t");
	printf("b->Display Maintenance History\n");
	printf("c->Calculate Next Service\t");
	printf("d-> Input Sensor Data\n");
	printf("f->Analyze Sensor Data\t");
	printf("e->Exit\n");
}

void addMaintenanceRecord (struct MaintenanceRecord maintenances[], int*numberOfMaintenanceRecords){

	for(int i=0;i<*numberOfMaintenanceRecords;i++){

		printf("Enter new maintenance recordserviceType  (e.g., Oil Change, Brake Check):");
		gets(maintenances[i].serviceType);

		printf("Enter new maintenance date in “DD/MM/YYYY” format:");
		gets(maintenances[i].date);

		for(int i=0;i<15;i++){
			if((maintenances[i].date[2] &&maintenances[i].date[6])!='/'){
				printf("reenter date in“DD/MM/YYYY” format:" );
				gets(maintenances[i].date[100]);
			}
		}

		printf("Kilometers recorded now at the time the maintenance is finished=");
		scanf(" %d",&maintenances[i].mileage);

		maintenances[i].nextServiceMileage=0;
		printf("A new maintenance record is added successfully\n");
	}
}

void displayMaintenanceHistory (struct MaintenanceRecord maintenances[],int numberOfMaintenanceRecords){
	if (numberOfMaintenanceRecords==0){
		printf("No maintenance records found.\n");
	}
	else{
		for(int i=0;i<numberOfMaintenanceRecords;i++){
				printf("Maintenance record %d:\n",i+1);
				printf("recordserviceType:\n");
				puts(maintenances[i].serviceType);
				printf("Date:\n");
				puts(maintenances[i].date);
				printf("Mileage: %d\n",maintenances[i].mileage);
				if((maintenances[i].nextServiceMileage)==0){
					printf("There are no mileage records\n");
				}
				else{
					printf("NextServiceMileage: %d\n",maintenances[i].nextServiceMileage);
				}

			}
	}
}

void calculateNextService (struct MaintenanceRecord maintenances[], int numberOfMaintenanceRecords){
	int duration=0;
	for(int i=0;i<numberOfMaintenanceRecords;i++){
		if(strcmp(maintenances[i].serviceType,"Oil Change")==0){
			duration=8000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if(strcmp(maintenances[i].serviceType,"Tire rotation")==0){
			duration=10000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if (strcmp(maintenances[i].serviceType,"Battery checks")==0){
			duration=15000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if (strcmp(maintenances[i].serviceType,"General inspection")==0){
			duration=20000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if (strcmp(maintenances[i].serviceType,"Air filters change")==0){
			duration=12000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if (strcmp(maintenances[i].serviceType,"Brake checks")==0){
			duration=15000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
		else if (strcmp(maintenances[i].serviceType,"Engine maintenance")==0){
			duration=30000;
			if(maintenances[i].mileage>duration){
				maintenances[i].nextServiceMileage=maintenances[i].mileage-duration;
			}
		}
	}
	printf("Calculating next service is done successfully.\n");
}

void inputSensorData (struct SensorsData sensors[], int*numberOfSensorReadings){
	int num;
	    printf("How many sensor readings do you want to add? ");
	    scanf("%d", &num);
	for(int i=0;i<num;i++){
		printf("Enter Sensor data:\n");
		printf("Enter engineTemperature:");
		scanf(" %f",&sensors[i].engineTemperature);
		getchar();
		printf("Enter oilPressure:");
		scanf(" %f",&sensors[i].oilPressure);
		getchar();
		printf("Enter tirePressure:");
		scanf(" %f",&sensors[i].tirePressure);
		getchar();
		printf("Enter  batteryVoltage:");
		scanf(" %f",&sensors[i].batteryVoltage);
		getchar();
		(*numberOfSensorReadings)++;
		printf("A new sensors readings is added successfully.");
	}
}
void analyzeSensorData (struct SensorsData sensors[], int numberOfSensorReadings){

	for(int i=0;i<numberOfSensorReadings;i++){
		if((sensors[i].engineTemperature == 0.0) || (sensors[i].oilPressure==0.0)|| (sensors[i].tirePressure==0.0) ||(sensors[i].batteryVoltage==0.0)){
			printf("There are no sensor readings found");
			return;
		}else{
			if((sensors[i].engineTemperature <= 100) && (sensors[i].oilPressure>=20) && (sensors[i].tirePressure>=30) && (sensors[i].batteryVoltage>=12)){
				printf("engineTemperature= %f\n",sensors[i].engineTemperature);
				printf("oilPressure= %f\n",sensors[i].oilPressure);
				printf("tirePressure= %f\n",sensors[i].tirePressure);
				printf("batteryVoltage= %f\n",sensors[i].batteryVoltage);
			}
			else{
				printf("WARNING!!! There are values that exceed or fall below specified limits");
			}
		}
	}
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	struct MaintenanceRecord maintenances[100];
	char option;
	struct SensorsData sensors[100];
	int num_of_maintenanceRecords =0;
	int num_of_sensorReadings=0;

	do{
		displayMenu();

		printf("Enter your option:");
		scanf(" %c",&option);

		switch(option){
		case 'a':
			printf("How many maintenance records do you want to add? ");
			scanf("%d", &num_of_maintenanceRecords);
			getchar();
			addMaintenanceRecord (maintenances, &num_of_maintenanceRecords);
			break;
		case 'b':
			displayMaintenanceHistory (maintenances,num_of_maintenanceRecords);
			break;
		case 'c':
			calculateNextService (maintenances,num_of_maintenanceRecords);
			break;
		case 'd':
			inputSensorData (sensors, &num_of_sensorReadings);
			break;
		case 'f':
			analyzeSensorData (sensors, num_of_sensorReadings);
			break;
		case 'e':
			printf("Exiting the program.");
			break;
		default:
			printf("Invalid option!! please choose an option from the list.");
			break;
		}

	}while(option!='e');

	return 0;
}
