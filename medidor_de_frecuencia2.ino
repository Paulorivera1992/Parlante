
long rango=2; // este es el rongo por el que se disparará la salida 2 y pasa a estado lógico 1
long ultimamedicion; // contiene el valor de la última medición que disparó a lógico 1, la salida 2
int ciclo=0; // 1=alto 0=bajo
int cambiodeciclo=0;
int picodetension;
int valledetension=1023;
long contadorvisualizacion;
long contadorciclo;

long rango1=2; // este es el rongo por el que se disparará la salida 2 y pasa a estado lógico 1
long ultimamedicion1; // contiene el valor de la última medición que disparó a lógico 1, la salida 2
int ciclo1=0; // 1=alto 0=bajo
int cambiodeciclo1=0;
int picodetension1;
int valledetension1=1023;
long contadorvisualizacion1;
long contadorciclo1;

void setup() {

 Serial.begin(9600);
 pinMode(A0, INPUT); // Se establece el pin analógico 0 como pin de lectura de datos.
 pinMode(A1, INPUT); // Se establece el pin analógico 0 como pin de lectura de datos.
}

void loop() {
 
 long sensorValue = analogRead(A0); // Se vuelca a la varibla sensorValue el valor de la tensión medida por el pin 0 analógico
 long sensorValue1 = analogRead(A1); 
   if (micros()>contadorvisualizacion+1000000) // Muestra por el puerto serie los resultados, transcurrido un segundo
   {    Serial.print(contadorciclo);
        Serial.print("\t");
        Serial.println(contadorciclo1);
        rango=(2+((picodetension-valledetension)/5)); // SE CALCULA EL GANGO MÁS ADECUADO PARA LA SEÑAL, CON EL FIN, DE REDUCIR ERRORES EN SEÑALES CON RUIDO DE FONDO
        rango1=(2+((picodetension1-valledetension1)/5));
        contadorvisualizacion=micros();//SE ASIGNA A LA VARIABLE CONTADORVISUALIZACIÓN EL TIEMPO EN MICROSENGUNDOS QUE LLEVA EL PROGRAMA EN EJECUCIÓN
        picodetension=sensorValue;//SE ASIGNA A LA VARIABLE PICODETENSIÓN EL VALOR DE LA TENSIÒN LEIDA POR EL PUERTO ANALÓGICO CERO
        picodetension1=sensorValue1;
        valledetension=sensorValue;//SE ASIGNA A LA VALLEDETENSION EL VALOR DE LA TENSIÒN LEIDA POR EL PUERTO ANALÓGICO CERO
        valledetension1=sensorValue1;
        contadorciclo=0; // SE PONE A CERO LOS CICLOS CONTADOS O HERCIOS.
        contadorciclo1=0;
   }  
//codigo asociado a sensor 1  
 if (sensorValue >= ( ultimamedicion+rango) ) // La salida 2 pasa a 1 logico si la tensión medida en la entrada analógica 0 es mayor que la anterior lectura + latensión de RANGO
 {
   ultimamedicion = sensorValue;  // SE ASIGANA A LA VARIABLE ULTIMAMEDICION EL VALOR LEIDO POR LA ENTRADA ANALÓGICA CERO
   ciclo=1;
   if (sensorValue>picodetension) // SI LA TENSIÓN MEDIDA POR LA ENTRADA CERO, ES LA MAYOR DETECTADA, SE ASIGNA A LA VARIABLE PICODETENSIÓN EL VALOR LEYDO POR AL ENTRADA CERO ANALÓGICA   
   {
   picodetension=sensorValue; // SE ASIGNA EL VALOR LEYDO POR LA ENTRADA CERO ANALÓGICA A LA VARIABLE PICODETENSIÓN.
   }   
 }
 if (sensorValue <= ( ultimamedicion-rango))  // La salida 2 pasa a 1 lógico si la tensión medida en la entrada analógica 0 es menor que la anterior lectura - la tensión de RANGO
 {
   ultimamedicion = sensorValue; // SE ASIGNA A LA VARIABLE ULTIMAMEDICIÓN LA LECTURA MEDIDA POR EL PUERTO ANALÓGICO CERO
   ciclo=0; // EL CICLO SE PONE A CERO, ES DECIR, QUE EL VOLTAJE EMPIEZA A BAJAR DESDE EL PICO DE TENSIÓN MÁS ALTA 
   if (sensorValue<valledetension) // SE CUMPLE LA CONDICIÓN SI LA TENSIÓN DETECTADA POR EL PUERTO ANALÓGICO CERO ES MENOR QUE LA CONTENIDA EN LA VARIABLE VALLEDETENSIÓN
   {
   valledetension=sensorValue; //Se asigna a la variable valledetensión el valor medido por la entrada analógica cero
   }
 }
if (ciclo==1 && cambiodeciclo==0)   
   { cambiodeciclo=1;
     contadorciclo++;
   }
   
if (ciclo==0 && cambiodeciclo==1)
   { cambiodeciclo=0;
   }

//codigo asociado a sensor 2
 if (sensorValue1 >= ( ultimamedicion1+rango1) ) // La salida 2 pasa a 1 logico si la tensión medida en la entrada analógica 0 es mayor que la anterior lectura + latensión de RANGO
 {
   ultimamedicion1 = sensorValue1;  // SE ASIGANA A LA VARIABLE ULTIMAMEDICION EL VALOR LEIDO POR LA ENTRADA ANALÓGICA CERO
   ciclo1=1;
   if (sensorValue1>picodetension1) // SI LA TENSIÓN MEDIDA POR LA ENTRADA CERO, ES LA MAYOR DETECTADA, SE ASIGNA A LA VARIABLE PICODETENSIÓN EL VALOR LEYDO POR AL ENTRADA CERO ANALÓGICA   
   {
   picodetension1=sensorValue1; // SE ASIGNA EL VALOR LEYDO POR LA ENTRADA CERO ANALÓGICA A LA VARIABLE PICODETENSIÓN.
   }   
 }
 if (sensorValue1 <= ( ultimamedicion1-rango1))  // La salida 2 pasa a 1 lógico si la tensión medida en la entrada analógica 0 es menor que la anterior lectura - la tensión de RANGO
 {
   ultimamedicion1 = sensorValue1; // SE ASIGNA A LA VARIABLE ULTIMAMEDICIÓN LA LECTURA MEDIDA POR EL PUERTO ANALÓGICO CERO
   ciclo1=0; // EL CICLO SE PONE A CERO, ES DECIR, QUE EL VOLTAJE EMPIEZA A BAJAR DESDE EL PICO DE TENSIÓN MÁS ALTA 
   if (sensorValue1<valledetension1) // SE CUMPLE LA CONDICIÓN SI LA TENSIÓN DETECTADA POR EL PUERTO ANALÓGICO CERO ES MENOR QUE LA CONTENIDA EN LA VARIABLE VALLEDETENSIÓN
   {
   valledetension1=sensorValue1; //Se asigna a la variable valledetensión el valor medido por la entrada analógica cero
   }
 }
if (ciclo1==1 && cambiodeciclo1==0)   
   { cambiodeciclo1=1;
     contadorciclo1++;
   }
   
if (ciclo1==0 && cambiodeciclo1==1)
   { cambiodeciclo1=0;
   }
}
