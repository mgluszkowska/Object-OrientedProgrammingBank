class Bank:

  def __init__(self, n, b):
    self.nazwa = n
    self.budzet = b
    self.liczbaKlientow = 0
    self.klienci = []
    print("\nNOWY BANK - %s" %self.nazwa)

  def daneBanku(self):
    print("")
    print("Bank %s (budzet %.2f zl)" %(self.nazwa, self.budzet))
    print("Oferujemy nastepujace konta:")
    print(" - Konto Osobiste (razem z bezplatna karta platnicza)")
    print(" - Konto Oszczednosciowe (oprocentowane 5% w skali roku)")
    print(" - Konto Junior (dla klientow w wieku 15-18 lat, oprocentowane 10% w skali roku, bez mozliwosci wyplaty)")

  def dodajKlienta(self, klient):
    self.klienci.append(klient)
    self.liczbaKlientow+=1

  def listaKlientow(self):
    print("LISTA KLIENTOW BANKU %s:" %self.nazwa)
    for element in self.klienci:
      print("%s %s" %(element.imie, element.nazwisko))

  def odejmijOdBudzetu(self, kwota):
    self.budzet-=kwota

  def dodajDoBudzetu(self, kwota):
    self.budzet+=kwota

  def pokazBudzet(self):
    print("\nBudzet banku %s: %.2f zl" %(self.nazwa, self.budzet))

class Konto:

  def __init__(self, b, k):
    self.saldo = 0
    self.wlasciciel = k
    self.wsk_na_bank = b 

  def wplata(self, kwota):
    self.saldo+=kwota
    print("Kwota %.2f zl zostala wplacona na konto." %kwota)
    print("Stan konta po wplacie: %.2f zl" %self.saldo)
    self.wsk_na_bank.dodajDoBudzetu(kwota)

class KontoOsobiste(Konto):
  liczbaOsobistych = 111111110
  def __init__(self, b, k):
    print("\nZakladam konto osobiste...")
    super().__init__(b, k)
    self.__class__.liczbaOsobistych += 1
    self.numer_konta = self.__class__.liczbaOsobistych
    print("\nUtworzono nowe konto osobiste dla klienta %s %s" %(k.imie, k.nazwisko))
    print("Numer konta: %s" %self.numer_konta)

  def wyplata(self, m):
    if self.saldo >= m:
      self.saldo-=m
      print("Kwota %.2f zl zostala wyplacona z konta." %m)
      print("Stan konta po wyplacie: %.2f zl" %self.saldo)
      self.wsk_na_bank.odejmijOdBudzetu(m)
    else:
      print("Brak wystarczajacych srodkow na koncie.")

class KartaPlatnicza:
  def __init__(self, kar):
    self.konto = kar
    print("Do konta zostala dolaczona karta platnicza")

  def platnosc(self, kwota):
    self.konto.wyplata(kwota)

class KontoOszczednosciowe(Konto):
  liczbaOszcz = 222111110
  def __init__(self, b, k):
    print("\nZakladam konto oszczednosciowe...")
    super().__init__(b, k)
    self.__class__.liczbaOszcz += 1
    self.numer_konta = self.__class__.liczbaOszcz
    self.procent=5 
    print("\nUtworzono nowe konto oszczednosciowe dla klienta %s %s" %(k.imie, k.nazwisko))
    print("Numer konta: %s" %self.numer_konta)

  def naliczZyski(self):
    self.saldo = self.saldo + self.saldo*self.procent/100

  def wyplata(self, kwota):
    if self.saldo >= kwota:
      self.saldo-=kwota
      print("Kwota %.2f zl zostala wyplacona z konta." %kwota)
      print("Stan konta po wyplacie: %.2f zl" %self.saldo)
      self.wsk_na_bank.odejmijOdBudzetu(kwota)
    else:
      print("Brak wystarczajacych srodkow na koncie")

class KontoJunior(Konto):
  liczbaJunior = 333111110
  def __init__(self, b, k):
    print("\nZakladam konto junior...")
    super().__init__(b, k)
    self.__class__.liczbaJunior += 1
    self.numer_konta = self.__class__.liczbaJunior
    self.procent = 10
    print("\nUtworzono nowe konto junior dla klienta %s %s" %(k.imie, k.nazwisko))
    print("Numer konta: %s" %self.numer_konta)

  def naliczZyski(self):
    self.saldo = self.saldo + self.saldo*self.procent/100

  def wyplata(self, kwota):
    print("Wyplacanie pieniedzy jest niemozliwe na koncie junior.")  

class Klient:
  def __init__(self, i, n, b):
    self.wsk_na_bank = b
    self.imie = i 
    self.nazwisko = n 
    print("\nNOWY KLIENT W BANKU %s - %s %s" %(self.wsk_na_bank.nazwa, self.imie, self.nazwisko))
    self.wsk_na_bank.dodajKlienta(self)
    self.wsk_na_konto_osob = 0
    self.wsk_na_konto_oszcz = 0
    self.wsk_na_konto_junior = 0

  def noweKontoOsobiste(self, ko):
    self.wsk_na_konto_osob = ko 
  
  def noweKontoOszczednosciowe(self, kon):
    self.wsk_na_konto_oszcz = kon 

  def noweKontoJunior(self, kont):
    self.wsk_na_konto_junior = kont 

  def nowaKarta(self, ka):
    self.wsk_na_karte = ka 

class Bankomat:

  def __init__(self, kli):
    print("\nWitaj w bankomacie %s %s!" %(kli.imie, kli.nazwisko))
    self.obecny_klient = kli
    self.osobiste_klienta = kli.wsk_na_konto_osob
    self.oszczednosciowe_klienta = kli.wsk_na_konto_oszcz
    self.junior_klienta = kli.wsk_na_konto_junior

  def stanKonta(self):
    if self.osobiste_klienta!=0:
      print("Stan konta: %.2f zl" %self.osobiste_klienta.saldo)
    else:
      print("Nie da sie sprawdzic stanu konta osobistego, bo nie zalozyles sobie takiego konta.")

  def stanOszczednosci(self):
    if self.oszczednosciowe_klienta!=0:
      print("Stan oszczednosci: %.2f zl" %self.oszczednosciowe_klienta.saldo)
    else:
      print("Nie da sie sprawdzic stanu konta oszczednosciowego, bo nie zalozyles sobie takiego konta.")

  def stanOszczednosciJunior(self):
    if self.junior_klienta!=0:
      print("Stan oszczednosci na koncie junior: %.2f zl" %self.junior_klienta.saldo)
    else:
      print("Nie da sie sprawdzic stanu konta junior, bo nie zalozyles sobie takiego konta.")

  def wplata(self, konto, kwota):
    print("\nRobie wplate na konto o numerze %s...\n" %konto.numer_konta)
    konto.wplata(kwota)

  def wyplata(self, konto, kwota):
    print("\nRobie wyplate z konta o numerze %s...\n" %konto.numer_konta)
    konto.wyplata(kwota)

  def przelew(self, z, na, kwota):
    print("\nRobie przelew z konta o numerze %s na konto o numerze %s...\n" %(z.numer_konta, na.numer_konta))
    if type(z)==KontoJunior:
      print("Nie mozna wyplacac pieniedzy z konta junior")
    else:
      z.wyplata(kwota)
      na.wplata(kwota)

  def nowyRok(self):
    if self.oszczednosciowe_klienta!=0:
      self.oszczednosciowe_klienta.naliczZyski()
      print("\nMinal rok i naliczono odsetki. ", end=" ")
      self.stanOszczednosci()
    if self.junior_klienta!=0:
      self.junior_klienta.naliczZyski()
      print("Stan konta junior po naliczeniu odsetek: %.2f zl" %self.junior_klienta.saldo)
    if self.oszczednosciowe_klienta==0 and self.junior_klienta==0:
      print("\nNie ma konta, dla ktorego mozna naliczyc odsetki.")

class Produkt:
  def __init__(self, n, c):
    self.nazwa = n
    self.cena = c

  def __str__(self):
    return "%s - %.2f zl" %(self.nazwa, self.cena)

class Zakupy:
  def __init__(self, k, lista):
    self.obecny_klient = k
    print("\nWitaj w sklepie, %s %s!" %(k.imie, k.nazwisko))
    self.oferta = lista

  def pokazOferte(self):
    print("\nPRODUKTY DOSTEPNE W NASZYM SKLEPIE:")
    licz = 1
    for element in self.oferta:
      print(licz, end=". ")
      print(element)
      licz += 1

  def kasa(self, karta):
    suma = 0.00
    print("Jakie produkty chcesz kupic?")
    print("(Podaj numer produktu i ilosc. Gdy dodasz juz wszystkie produkty, wcisnij 0)")
    koszyk = "WYBRALES NASTEPUJACE PRODUKTY:\n"
    while True:
      print("Numer produktu:")
      prod = input()
      if prod.isdigit():
        prod = int(prod)
        if prod > 0 and prod<=len(self.oferta)+1:
          print("Ilosc: ")
          ilosc = input()
          if ilosc.isdigit():
            ilosc = int(ilosc)
            koszyk += self.oferta[prod-1].nazwa + " - " + str(self.oferta[prod-1].cena) + " zl"
            koszyk += " (" + str(ilosc) + "szt.)\n"
            suma = suma + (self.oferta[prod-1].cena *   ilosc)
          else:
            print("Nieprawidlowa ilosc produktu")
        elif prod>len(self.oferta)+1:
          print("Nieprawidlowy numer produktu.")
        else:
          break
      else:
        print("Nieprawidlowy numer produktu")
        continue
    print(koszyk)
    print("\nSuma kosztow: %.2f zl" %suma)
    print("Czy na pewno chcesz kupic te produkty? (Wpisz tak lub nie) ", end=" ")
    wybor = input() 
    if wybor=="tak":
      karta.platnosc(suma)
      print("Rachunek uregulowany. Dziekujemy za zakupy!")
    else:
      print("Zakupy anulowane")

###################
#TWORZE PRZYKLADOWE PRODUKTY, ZEBY BYLO CO KUPOWAC
lista_produktow = []
lista_produktow.append(Produkt("maslo", 5.99))
lista_produktow.append(Produkt("jogurt", 3.49))
lista_produktow.append(Produkt("bulka", 0.39))
lista_produktow.append(Produkt("kurczak", 16.49))
lista_produktow.append(Produkt("mleko", 2.69))
lista_produktow.append(Produkt("czekolada", 2.99))
lista_produktow.append(Produkt("herbata", 5.29))
lista_produktow.append(Produkt("kawa", 24.49))
lista_produktow.append(Produkt("maka", 1.99))
lista_produktow.append(Produkt("cukier", 1.49))

#TWORZE BANKI
b1 = Bank("Super Bank", 1000.00)
b1.daneBanku()
b2 = Bank("Bank Polski", 10000)

#TWORZE KLIENTOW
marta = Klient("Marta", "Gluszkowska", b1)
jan = Klient("Jan", "Kowalski", b2)

#ZAKLADAM KONTA DLA KLIENTA MARTA
osob1 = KontoOsobiste(b1, marta)
marta.noweKontoOsobiste(osob1)
karta1 = KartaPlatnicza(osob1)
marta.nowaKarta(karta1)
oszcz1 = KontoOszczednosciowe(b1, marta)
marta.noweKontoOszczednosciowe(oszcz1)
jun1 = KontoJunior(b1, marta)
marta.noweKontoJunior(jun1)

#ZAKLADAM KONTA DLA KLIENTA JAN
osob2 = KontoOsobiste(b2, jan)
jan.noweKontoOsobiste(osob2)
karta2 = KartaPlatnicza(osob2)
jan.nowaKarta(osob2)
oszcz2 = KontoOszczednosciowe(b2, jan)
jan.noweKontoOszczednosciowe(oszcz2)
jun2 = KontoJunior(b2, jan)
jan.noweKontoJunior(jun2)

#MARTA WCHODZI DO BANKOMATU
b = Bankomat(marta) 
b.stanKonta() 
b.stanOszczednosci()
b.stanOszczednosciJunior()
b.wplata(marta.wsk_na_konto_osob, 100.99)
b.wplata(marta.wsk_na_konto_oszcz, 500)
b.wyplata(marta.wsk_na_konto_osob, 20.50)
b.przelew(marta.wsk_na_konto_oszcz, marta.wsk_na_konto_junior, 400)
b.przelew(marta.wsk_na_konto_junior, marta.wsk_na_konto_oszcz, 400)
b.wyplata(marta.wsk_na_konto_junior, 300)
b.nowyRok()
b.stanKonta()
b.stanOszczednosci()
b.stanOszczednosciJunior()

#ZAKUPY
z = Zakupy(marta, lista_produktow)
z.pokazOferte()
z.kasa(marta.wsk_na_karte)

#JAN WCHODZI DO BANKOMATU
ba = Bankomat(jan) 
ba.stanKonta() 
ba.stanOszczednosci()
ba.stanOszczednosciJunior()
ba.wplata(jan.wsk_na_konto_osob, 200)
ba.przelew(jan.wsk_na_konto_osob, marta.wsk_na_konto_osob, 100)

#SPRAWDZENIE BUDZETU BANKOW
b1.pokazBudzet()
b1.listaKlientow()
b2.pokazBudzet()
b2.listaKlientow()