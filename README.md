# Brainf*ck interpreter
Dit is een Brainf*ck interpreter geschreven is C++.
## Hoe het werkt
Deze interpreter werkt dynamisch: het gebruikt een vector in plaats van een pointer om naar indexes te verwijzen. Deze vector is te vergroten terwijl het programma al bezig is.  

## Voorbeelden
Hello.bf: 
```bf
++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.
```  
Een programma dat input pakt, dit uitprint + het ASCII nummer op een (n)*ewline* (dit is met eigen toegevoegde syntax):  
```bf
,.n'
```
