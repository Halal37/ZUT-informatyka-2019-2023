import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;
import java.util.List;


public class main {
       public static void main(String[] args){
              EntityManagerFactory emf = Persistence.createEntityManagerFactory("labs");
              EntityManager em = emf.createEntityManager();

              Person p = new Person();
              p.setFamilyName("Wiadra");
              p.setFirstName("Ewa");
              p.setAge(41);

              em.getTransaction().begin();
              em.persist(p);
              em.getTransaction().commit();
              //6
              Query q = em.createQuery("SELECT p from Person p", Person.class);
              List<Person> people = q.getResultList();

              for(Person prsn : people){
                     System.out.println(prsn.getFirstName() + " " + prsn.getFamilyName());
              }
              //7
              Query quereight = em.createQuery("UPDATE Person p SET p.age=18 WHERE p.age < 18");
              em.getTransaction().begin();
              quereight.executeUpdate();
              em.getTransaction().commit();

              //8S
              Query qc = em.createQuery("SELECT p from Person p", Person.class);
              System.out.println("Liczba osob: " + people.size());

              //9
              Query qa = em.createQuery("SELECT p from Person p where p.firstName like 'a%'", Person.class);
              List<Person> peoplea = qa.getResultList();

              for(Person prsna : peoplea){
                     System.out.println(prsna.getFirstName() + " " + prsna.getFamilyName());
              }
       }
}
