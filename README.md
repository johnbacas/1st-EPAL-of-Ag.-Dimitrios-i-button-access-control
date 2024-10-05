# Έργο για το διαγωνισμό Ρομποτικής και Physical Computing

## Τίτλος έργου: Έλεγχος πρόσβασης με iButton.

Περιγραφή:
Το σύστημα που θα σχεδιαστεί θα κάνει έλεγχο πρόσβασης για άτομα που φέρουν ηλεκτρονικό κλειδί.
Συγκεκριμένα ο μικροελεγκτής του Arduino θα διαβάζει μέσω ενός reader ένα ηλεκτρονικό κλείδί - ID που βασίζεται στην τεχνολογία i-button.
Το προτόκολλο επικοινωνίας είναι το 1-Wire που χρησιμοποιεί μόνο ένα καλώδιο για την επικοινωνία master -slave.
Το συγκεκριμενο i-button που θα χρησιμοποιηθεί περιέχει ένα μοναδικό ID number 64 bit.
Στη συνέχεια ο μικροελεγκτής θα ελέγχει αν το συγκεκριμένο ID έχει πρόσβαση σε συγκεκριμένη είσοδο σε κάποιο χώρο.
Αν ναι, το σύστημα μέσω ενός ρελαί θα ενεργοποιεί το ηλεκτρικό κυπρί μια πόρτας και αυτή θα μπορεί να ανοίξει.

Το σύστημα μπορεί να χρησιμοποιηθεί σε εισόδους πολυκατοικιών, αντί του κλασσικού κλειδιού και πιο εξειδικευμένα σε επιχειρήσεις που θέλουν να ελέγχουν την πρόσβαση των υπαλλήλων σε συγκεκριμένους χώρους της επιχείρησης ανάλογα με κάποια δικαιώματα πρόσβασης.

Υλικά που θα χρειαστούν:
1. Arduino Uno
2. i-button serial number(DS1990 - ROM only 64 bit), 1-Wire protocol
https://www.maximintegrated.com/en/products/ibutton/memory-products/DS1990A.html
3. i-button reader (DS9092 - Touch probe read head)
https://www.maximintegrated.com/en/products/ibutton/ibutton/DS9092.html
4. Οθόνη LCD 16x2
5. Relay module
6. Ηλεκτρικό Κυπρί πόρτας
https://stokostos.gr/alarm/ilektromagnitikes/aei-dls-81.html

Το κύκλωμα:
![AccessControlCircuit](https://user-images.githubusercontent.com/7252559/56303159-002b0300-6144-11e9-97eb-e698b56914a3.jpg)

Δείτε το βίντεο στο παρακάτω link:

[![YouTube Video](https://img.youtube.com/vi/1vuWFKG8IxQ/0.jpg)](https://youtu.be/1vuWFKG8IxQ)
