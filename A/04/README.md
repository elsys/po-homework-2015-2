Домашно 4
===

Краен срок за предаване: 2016.04.10 23:59:59 

Задача 1 - ISBN
---
Точки: 5

На входа получавате стринг с дължина до 20 символа. Да се провери, дали въведеният стринг е валиден [ISBN13](https://en.wikipedia.org/wiki/International_Standard_Book_Number) номер. Да е валиден означава:
  * да започва с 978 или 979
  * да бъде с дължина 13
  * чексумата на номера да е вярна

На стандартния изход да се покаже дали ISBN13 номера е верен и ако издателката къща е една от следните да се покаже името на издателската къща

```
Номер - Издателска къща
933346 - Bluebridge
55583 - Alyson Books
4210 - FUNimation Productions, Ltd.
01 - Pyramid Books
```

Примерен вход:
```
978-1-55583-868-3
```
Изход:
```
1
Alyson Books
```

Примерен вход:
```
978-0-330-25864-7
```
Изход:
```
1
```

Примерен вход:
```
9178-1-55583-868-3
```
Изход:
```
0
```

Задача 2 - Doors
---
Точки: 5

На стандартния вход получавате списък от команди докато не видите EOF. Двете възможни команди са `button_clicked` и `cycle_complete`.

След въвеждането на всяка команда трябва да има изход, който е един от следните стрингове `CLOSED`, `OPENING`, `OPEN`, `CLOSING`, `STOPPED_WHILE_CLOSING`, `STOPPED_WHILE_OPENING`

Приемете, че имаме гаражна врата, която в началото е затворена - има състояние "CLOSED". При прочитане на командата `button_clicked` вратата започва да се отваря. Ако се прочете `cycle_complete` значи вратата се е отворила напълно, а ако се прочете `button_clicked` състоянието става `STOPPED_WHILE_OPENING`. Ако вратата е спряна в състояние `STOPPED_WHILE_OPENING` и отново се подаде команда `button_clicked` вратата започва да се затваря.

**Забележка**: Ако вратата е в състояние `STOPPED_WHILE_*` няма как да се подаде команда `cycle_complete`.

Да се напише програма, която по подаден списък от команди връща изход с действията, които са се случили.

**Забележка**: Винаги на първия ред се изпива началното състояние на вратата т.е. `Door: CLOSED`

Примерен вход:
```
button_clicked
cycle_complete
button_clicked
button_clicked
button_clicked
button_clicked
button_clicked
cycle_complete
```
Изход:
```
Door: CLOSED
Door: OPENING
Door: OPEN
Door: CLOSING
Door: STOPPED_WHILE_CLOSING
Door: OPENING
Door: STOPPED_WHILE_OPENING
Door: CLOSING
Door: CLOSED
```

Задача 3 - Digits
---
Точки: 7

На първия ред от стандартния вход получавате последователност от цифри (максимум 10 на брой и могат да се повтарят). Между всеки 2 цифри можете да слагате операцийте `+` или `-`. На втория ред от стандартния вход получавате число, което се стремим да получим на базата на първите цифри с добавяне на операцийте `+` и `-` между всеки две цифри.

На стандартния изход да се изведадат всички комбинации, който могат да доведат до получаване на числото (без да размествате позицията на цифрите). Ако няма как да получите желаното число изведете -1.

**Забележка**: Ако има повече от една комбинация да се подредят в низходящ ред, ако ги сравняваме като стрингове.

Примерен вход:
```
2345
14
```
Изход:
```
2+3+4+5=14
```

Примерен вход:
```
23457
7
```
Изход:
```
2-3-4+5+7=7
2+3+4+5-7=7
```

Примерен вход:
```
2345
17
```
Изход:
```
-1
```
