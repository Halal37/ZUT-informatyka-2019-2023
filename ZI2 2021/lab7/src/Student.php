<?php
namespace Wojtek\Lab7;
use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;
/**
 * @ORM\Entity
 *  @ORM\Table(name="student")
 */
class Student{
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
 * @ORM\ManyToOne(targetEntity="Classs",inversedBy="students", cascade={"persist"})

 */
    private $classs;

    public function getClasss(){
        return $this->classs;
    }
    public function setClasss($classs){
        $this->classs = $classs;
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