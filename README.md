# Ontwerp van het blokje duwen
Middlescanner wordt in de constructor meegegeven aan blockPusher vanuit hogere klassen, dit is een reference (&)

zolang het duwen van het blokje nodig is wordt update() van Pusher aangeroepen elke update cycle van de arduino, die update dan weer de benodigde klassen zoals in het ontwerp staat aangegeven, de update() cycle mag niet worden vastgehouden door een thread en mag niet langer dan een fractie van een seconde duren.
![Ontwerp blokje duwen](https://github.com/user-attachments/assets/957ca5ea-0df7-493b-acdd-bbac02573eda)
Ontwerp pusher:
![Ontwerp pusher](https://github.com/user-attachments/assets/bf014606-310f-4c9d-bc03-ce8393ebd7cf)
Ontwerp blockpusher:
![Ontwerp blockpusher](https://github.com/user-attachments/assets/370f4592-4248-4608-9aa1-7d555ad1952f)
Ontwerp proximityinterface
![Ontwerp proximityinterface](https://github.com/user-attachments/assets/e87d179f-90d2-429f-ad69-5065b48ccaae)
Ontwerp retreater
![Ontwerp retreater](https://github.com/user-attachments/assets/8d178ba8-740d-4274-bea4-daff1afdc116)
Ontwerp measurer
![Ontwerp measurer](https://github.com/user-attachments/assets/dd77d475-29df-45bf-8a45-179fccacb3ae)
Ontwerp Turner
![Ontwerp turner](https://github.com/user-attachments/assets/f8c2ec86-6ac7-499e-861d-b623ce9f0b7c)
ontwerp motors
![Ontwerp motors](https://github.com/user-attachments/assets/9b97b338-5f3e-4236-a294-57d4c9c33681)
