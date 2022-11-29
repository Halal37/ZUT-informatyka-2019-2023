package ai2.SpringBoot;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.http.ResponseEntity;

import javax.annotation.Resource;
import java.util.List;


@RestController
@RequestMapping("/api")
public class PeopleRestController {
    @Resource(name = "peopleService")
    PeopleService peopleService;


    @Autowired
    public PeopleRestController(PeopleService peopleService) {
        this.peopleService = peopleService;
    }

    @GetMapping("/people")
    public List<Person> getPeople() {
        return peopleService.getPeople();
    }

    @GetMapping("/people/{index}")
    public ResponseEntity<Person> getPerson(@PathVariable int index) {
        try {
            return ResponseEntity.ok(peopleService.getPerson(index));
        } catch (Exception e) {
            return ResponseEntity.notFound().build();

        }
    }

    @PostMapping("/people")
    public ResponseEntity<?> addPerson(@RequestBody Person person) {
        peopleService.addPerson(person);
        return ResponseEntity.ok().build();
    }

    @PutMapping("/people/{index}")
    public ResponseEntity<?> updatePerson(@PathVariable int index, @RequestBody Person person) {
        try {
            peopleService.getPeople().set(index, person);
            return ResponseEntity.ok().build();
        } catch (Exception e) {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/people/{index}")
    public ResponseEntity<?> deletePerson(@PathVariable int index) {
        try {
            peopleService.getPeople().remove(index);
            return ResponseEntity.ok().build();
        } catch (Exception e) {
            return ResponseEntity.notFound().build();
        }
    }
}

