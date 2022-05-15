<?php
namespace Wojtek\Lab7;
use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;
/**
 * @ORM\Entity
 * @ORM\Table(name="subject")
 */
class Subject{
/** 
 * @ORM\Id
 * @ORM\Column(name="id", type="integer")
 * @ORM\GeneratedValue(strategy="IDENTITY")
*/
protected $id;
 /**
 * @ORM\Column(name="name",type="string")
 */
protected $name;
/**
* @ORM\ManyToOne(targetEntity="Teacher",inversedBy="subjects", cascade={"persist"})
*/
private $teachers;
/**
* @ORM\ManyToMany(targetEntity="Classs",inversedBy="subjects", cascade={"persist"})

*/
protected $classs;
public function __construct()
{
    $this->classs = new ArrayCollection();
}

//   public function getClasss(){
//       return $this->classs;
//  }
    /**
     * @return mixed
     */
public function setClasss($classs){
    $this->classs = $classs;
}
    /**
     * @return mixed
     */
public function getTeachers(){
    return $this->teachers;
}
    /**
     * @return mixed
     */
public function setTeachers($teachers){
    $this->teachers = $teachers;
}
    /**
     * @return mixed
     */
public function getId(){
    return $this->id;
}
    /**
     * @return mixed
     */
public function setId($id){
    $this->id = $id;
}
    /**
     * @return mixed
     */
public function getName(){
    return $this->name;
}
    /**
     * @return mixed
     */
public function setName($name){
    $this->name = $name;
}
}
?>