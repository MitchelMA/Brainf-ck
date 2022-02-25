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
## Gebruik
Je kan het programma gebruiken op de volgende manieren:  
Als je een bestand wilt uitlezen:
```terminal
> main f "path-to-file"
```
Als je rechtstreeks wilt uitlezen:
```terminal
> main s "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."
```
Of gewoon zoals voorheen. De "f" kan gewoon weg worden gelaten en dan gaat het programma er van uit dat je een bestand wilt lezen
```terminal
> main "path-to-tile"
```