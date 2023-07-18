# Addition von zwei Zahlen
Binäre Zahlen lassen sich genauso addieren wie dezimale Zahlen. 
![addition](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/d061bd8d-b175-459b-bb1c-6dc746638d45 "Positive Zahlen addieren")
Da Binäre Zhalen nur als 0 und 1 dastellbar sind, enteht bei 1+1 schon ein Übertrag (im Bild gekennzeichnet mit den kleinen einsen).

### Negative Zahlen
Diese Rechenarithmetik lässt sich auch für negative Binäre Zahlen verwerden. Daher funktioniert eine Addierer Schaltung auch für negative Zahlen - später mehr.
Negative Zahlen lassen z.B. als 2 er Komplement darstellen. Dafür werden die positiven Zahlen invertiert und +1 gerechnet. Beispielsweise ist die 1 Binär 0001. 
Für die -1 müsste man das jetzt also invertieren (1110) und +1 rechnen, das ergibt 1111 für die Binäre -1. 
Hier die Wertetabelle und zwei Beispielrechnungen: 
![negative zahl](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/b00e1c0e-98fc-4f7b-8f2d-80bdb859cc03 "Negative Zahle 'addieren'")

#2 Bit Addierer Schaltung 
Der 2 Bit Addierer besteht aus einem Halbaddierer und einem Volladdierer. Man kann zwei 2 Bit Zahlen addieren. Also Zahlen von 0 bis 6 darstellen. 
Hier die Skizze der Schaltung Schaltung, die blauen Zahlen sind die Pins der Ein- und Ausgänge: 
![2 bit addierer schaltung](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/fed038e6-e17a-45b8-a5e1-40cc297db556 "2 Bit Addierer Schaltung")
Welche Pins wo liegen liest man an dem Datenblatt des jeweiligen Gatters ab.
Beispielsweise ist diese Aufzeichnung aus dem Dateblatt zum 74LS86 (XOR Gatter): 
![74ls86 datenblatt](https://github.com/oguzmum/2_und_3_Bit_Addierer/assets/91074322/e209c90f-bd41-4063-8e8c-cd0998265f3a "Pins des 74LS86")
Die A's und B's sind die Eingänge und die Y's die Ausgänge. Pin 7 wird an Masse angeschlossen und Pin 14 an Versorgungsspannung.

Die Fertige Schaltung sieht dann wie folgt aus:
![2 bit schaltung echt](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/ab606419-742d-43e0-aefe-f80e50bace6f "2 Bit Addierer")


# 3 Bit Addierer
Der 3 Bit Addierer besteht aus einem Halbaddierer und zwei Volladdierern. Es lassen sich die Zahlen von 0 bis 14 darstellen.
Im Prinzip erweitert man also die 2 Bit Addierer Schaltung um einen Voladdierer. Der Übertrag wird in jetzt als Eingang für das XOR und das AND Gatter benutzt.
Hier die Skizze der Schaltung: 
![3 bit addierer skizze](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/e12fc59a-065a-422d-85e3-ebd8e68e8dd1)

### Lageplan
Der Lageplan zeigt, welche Logikgatter wo sitzen und wie ich die Wertigkeit der Biteingänge gewählt habe. Das MSB (most significant Bit) ist a_2 bzw b_2 und das LSB(least significant) ist a_0 bzw b_0. Beim 2 Bit Addierer ist das a_2, b_2, und das XOR2 sowie das AND2 ncith in der Schaltung. 
Hier der Lageplan: 
![lageplan](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/239d9f7b-bdd4-4259-b8d3-b3313d50c71c "Lageplan")
Als Logikgatter habe ich die 74LS benutzt.

Die fertige Schaltung des 3 Bit Addierer sieht wie folgt aus: 
![IMG_0194](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/4793582b-9818-4ac0-9da3-383dc854fefe "3 Bit Addierer fertig")

# 7 Segment Display
Man kann mithilfe des Arduino die Summe einlesen, die Dezimale Zahl berechnen und das 7 Segment Display so ansteuern, dass die addierte Zahl angezeigt wird. 
Die Logik für das Display habe ich in folgender Tabelle festgehalten: 
![7segmentdisplay](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/637016ad-9d8a-4203-b787-729926e0d37b "Beschaltung für das 7 Segment Display")
In dieser Tabelle sind jetzt nur die positiven Zahlen dargestellt. Für die negativen Zahlen habe ich den Punkt unten rechts am Display genutzt ('Ersatz' für das minus Zeichen).

Der Code für die Ansteuerung [beim 2 Bit Addierer ist hier zu finden](https://github.com/oguzmum/2_und_3Bit_Addierer/blob/main/2BitAddierer_7Segment.ino "2 Bit Addierer Code") und für den [3 Bit Addierer hier.](https://github.com/oguzmum/2_und_3Bit_Addierer/blob/main/3_bit_addierer_7segDisplay.ino "3 Bit Addierer Code")  

# Fertige Schaltung mit 2 Bit Addierer und 7 Segment Display
![IMG_0215](https://github.com/oguzmum/2_und_3Bit_Addierer/assets/91074322/f04bff29-9865-49fc-ba74-a37ed07a3c9a "Fertige Schaltung")
