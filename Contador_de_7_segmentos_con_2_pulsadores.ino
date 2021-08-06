int contador;

void setup(){ // Inicia el ciclo de configuración
  //Forma de declarar la función pinMode
  
  //pinMode (#de Pin a usar , Forma en la que se va a usar );
  //Forma en la que se va a usar:
  // - Entrada --> Leer algo --> INPUT
  // - Salida --> Enviar voltaje --> OUTPUT
  pinMode(9,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10, INPUT);
  contador = 0; 
}// Termina el ciclo de configuración

void loop(){  // Inicia el ciclo repetitivo+
  
  
  // Para leer un dato usamos la función digitalRead
  //Forma de declarar la función digitalRead
  //  digitalRead(El pin que quiero leer) 
  
  //Forma de declarar la condicional if
  // if (La condición a evaluar){
  //    Instrucciones a realizar si la condición se cumple
  //}
  
  //Estructura que evalúa el estado del botón
  if(digitalRead(9) == 1 ){
   // Forma de declarar la instrucción delay
    // delay (Cantidad de tiempo a esperar en MILISEGUNDOS)
    delay(100);
    if(digitalRead(9) == 1){
      contador = contador +1;
      //contador +=1;
    } 
  }
  if(digitalRead(10) == 0){
    delay(100);
      if(digitalRead(10)== 0){
      contador -=1;
    }
  }
  

  //Estructura que evalúa el valor de contador
  if( contador  == 0){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
   
  }
  
   if( contador  == 1){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
    
    
  }
  
   if( contador  == 2){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
   
  }
  
   if( contador  == 3){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    
 digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  }
  
   if( contador  == 4){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
     digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
    
    
  }
     if( contador  == 5){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    
     digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  }
  
   if( contador  == 6){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
    
  }
  
   if( contador  == 7){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    
   digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  }
   if( contador  == 8){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    
    digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  }
  
   if( contador  == 9){
    //Forma de declarar la instrucción digitalWrite
    // digitalWrite (# del pin que voy a usar , Voltaje a enviar );
    //Voltaje a enviar
    // - HIGH (ALTO) = 1
    //- LOW (BAJO) = 0
    
    digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  }
    if(contador>9){
     contador = 0;
   
    }
  if(contador<0){
    contador = 9;
  }
  
}// Termina el ciclo repetitivo
