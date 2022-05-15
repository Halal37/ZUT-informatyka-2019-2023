<?php
namespace Wojtek\Lab7;
use Doctrine\ORM\Mapping;
use Doctrine\ORM\Query\ResultSetMapping;
use Doctrine\Common\Collections\ArrayCollection;
require_once "bootstrap.php";
use Wojtek\Lab7\Subject;
use Wojtek\Lab7\Classs;
use Wojtek\Lab7\Teacher;
use Wojtek\Lab7\Student;



$cl1 = new Classs();
$cl1->setName("IA");
$cl1->setYear(1);


$cl2 = new Classs();
$cl2->setName("IIC");
$cl2->setYear(2);


$cl3 = new Classs();
$cl3->setName("IIIB");
$cl3->setYear(3);


echo $cl1->getName(), "  ";
$name = "Jan";
$lastName = "Mojski";
$l1 = new ArrayCollection();
$l2 = new ArrayCollection();
$l3 = new ArrayCollection();

for ($i = 0; $i < 5; ++$i) {
    $l1[$i] = new Student();
    $l1[$i]->setFirstName($name . $i);
    $l1[$i]->setLastName($lastName . $i);
    $l1[$i]->setClasss($cl1);
}

for ($i = 0; $i < 5; ++$i) {
    $l2[$i] = new Student();
    $l2[$i]->setFirstName($name . ($i + 1) * 20);
    $l2[$i]->setLastName($lastName . ($i + 1) * 20);
    $l2[$i]->setClasss($cl2);
}

for ($i = 0; $i < 5; ++$i) {
    $l3[$i] = new Student();
    $l3[$i]->setFirstName($name . ($i + 5) * 15);
    $l3[$i]->setLastName($lastName . ($i + 5) * 15);
    $l3[$i]->setClasss($cl3);
}
echo $l1[0]->getFirstName(),"        ";

$cl1->setStudents($l1);
$cl2->setStudents($l2);
$cl3->setStudents($l3);

echo $cl1->getStudents()[2]->getFirstName(),"        ";



$cls = array($cl1, $cl2, $cl3);

$c1 = new Subject();
$c1->setName("chemia");

$c1->setClasss($cls);
$c2 = new Subject();
$c2->setName("biologia");
$c2->setClasss($cls);

$c3 = new Subject();
$c3->setName("fizyka");
$c3->setClasss($cls);

$c4 = new Subject();
$c4->setName("informatyka");
$c4->setClasss($cls);


$Subjects = array($c1, $c2, $c3, $c4);

$cl1->setSubjects($Subjects);
$cl2->setSubjects($Subjects);
$cl3->setSubjects($Subjects);



$t1 = new Teacher();
$t1->setFirstName("Ania");
$t1->setLastName("Frania");
$t1->setClasss($cl1);

$t2 = new Teacher();
$t2->setFirstName("Tomasz");
$t2->setLastName("Kania");
$t2->setClasss($cl2);
$t2->setSubjects($Subjects);
$t3 = new Teacher();
$t3->setFirstName("Adam");
$t3->setLastName("Saski");
$t3->setClasss($cl3);
$t3->setSubjects($Subjects);


$c1->setTeachers($t1);
$c2->setTeachers($t2);
$c3->setTeachers($t3);

$cl2->setTeachers($t2);
$cl3->setTeachers($t3);


$em->persist($l1[0]);
$em->persist($l1[1]);

echo $cl1->getId();
$em->flush();




?>