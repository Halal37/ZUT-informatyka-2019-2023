<?php
namespace Wojtek\Lab7;
use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;
/**
 * @ORM\Entity
 *  @ORM\Table(name="teacher")
 */
class Teacher{
    /** 
 * @ORM\Id
 * @ORM\Column(name="id",type="integer")
 * @ORM\GeneratedValue
*/
protected $id;
 /**
 * @ORM\Column(type="string")
 */
protected $firstname;
 /**
 * @ORM\Column(type="string")
 */
protected $lastname;
/**
* @ORM\OneToOne(targetEntity="Classs",inversedBy="teachers", cascade={"persist"})
*/
private $classs;
/**
* @ORM\OneToMany(targetEntity="Subject",mappedBy="teachers", cascade={"persist"})
*/
private $subjects;

public function __construct()
{
    $this->subjects = new ArrayCollection();
}

public function getClasss(){
    return $this->classs;
}
public function setClasss($classs){
    $this->classs = $classs;
}

public function getSubjects(){
    return $this->subjects;
}
public function setSubjects($subjects){
    $this->subjects = $subjects;
}

public function getId(){
    return $this->id;
}
public function setId($id){
    $this->id = $id;
}

public function getLastname(){
    return $this->lastname;
}
public function setLastname($lastname){
    $this->lastname = $lastname;
}

public function getFirstname(){
    return $this->firstname;
}
public function setFirstname($firstname){
    $this->firstname = $firstname;
}
}
?>