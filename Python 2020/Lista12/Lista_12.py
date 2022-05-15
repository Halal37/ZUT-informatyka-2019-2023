#zad1
import xml.etree.ElementTree
drzewo=xml.etree.ElementTree.parse("C:\Lab11\pierwszy.xml")
korzen=drzewo.getroot()
for i in korzen.iter('item'):
 print(i.attrib)
#zad2
for i in korzen.iter('item'):
 print(i.text)
 #zad3
print(korzen[0][1].attrib,korzen[0][1].text)
#zad4
root=xml.etree.ElementTree.Element('root')
uczelnia=xml.etree.ElementTree.SubElement(root,'uczelnia')
uczelnia.set('Nazwa','SIMS')
student1=xml.etree.ElementTree.SubElement(uczelnia,'student')
student2=xml.etree.ElementTree.SubElement(uczelnia,'student')
student3=xml.etree.ElementTree.SubElement(uczelnia,'student')
student1.set('Nrindeksu','12333')
student1.text='Anna Kowalska'
student2.set('Nrindeksu','23795')
student2.text='Przemyslaw Nowak'
student3.set('Nrindeksu','65789')
student3.text='Piotr Pilawka'
dane=xml.etree.ElementTree.tostring(root).decode('utf-8')
plik=open("C:\\Lab11\\uczelnia.xml","w")
plik.write(dane)
plik.close()
#zad5
suma=0
zad5_drzewo=xml.etree.ElementTree.parse("C:\Lab11\sklep.xml")
zad5_korzen=zad5_drzewo.getroot()
for i in zad5_korzen.iter('vitem'):
 if(i.findtext('vitem')==None):
     print(i.attrib)
     suma+=1
print("Tyle vitemow ",suma)
#zad6
zad6_drzewo=xml.etree.ElementTree.parse("C:\Lab11\sklep.xml")
zad6_korzen=zad6_drzewo.getroot()
zad6_korzen[0][7].attrib["name"]="oreilly"
dane_2=xml.etree.ElementTree.tostring(zad6_korzen).decode('utf-8')
plik_2=open("C:\\Lab11\\sklep2.xml","w")
plik_2.write(dane_2)
plik_2.close()