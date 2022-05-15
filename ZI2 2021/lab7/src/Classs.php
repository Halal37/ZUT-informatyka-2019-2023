<?php
namespace Wojtek\Lab7;
use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;
/**
 * @ORM\Entity
 *  @ORM\Table(name="classs")
 */
class Classs{
    /** 
 * @ORM\Id
 * @ORM\Column(name="id",type="integer")
 * @ORM\GeneratedValue
*/
protected $id;
/**
 * @ORM\Column(type="string")
 */
protected $name;
 /**
 * @ORM\Column(type="integer")
 */
protected $year;
/**
* @ORM\ManyToMany(targetEntity="Subject",mappedBy="classs", cascade={"persist"})
*/
protected $subjects;
//public function __construct()
//{
//    $this->subjects = new ArrayCollection();
//}

/**
* @ORM\OneToMany(targetEntity="Student",mappedBy="classs", cascade={"persist"})
*/
private $students;

public function __construct()
{
    $this->subjects = new ArrayCollection();
    $this->students = new ArrayCollection();
}
/**
* @ORM\OneToOne(targetEntity="Teacher",inversedBy="classs", cascade={"persist"})
*/
private $teachers;

public function getSubjects(){
    return $this->subjects;
}
public function setSubjects($subjects){
    $this->subjects = $subjects;
}

public function getStudents(){
    return $this->students;
}
public function setStudents($students){
    $this->students = $students;
}

public function getTeachers(){
    return $this->teachers;
}
public function setTeachers($teachers){
    $this->teachers = $teachers;
}

public function getId(){
    return $this->id;
}
public function setId($id){
    $this->id = $id;
}
    /**
     * @return mixed
     */
public function getName(){
    return $this->name;
}
public function setName($name){
    $this->name = $name;
}

public function getYear(){
    return $this->year;
}
public function setYear($year){
    $this->year = $year;
}
}
?>