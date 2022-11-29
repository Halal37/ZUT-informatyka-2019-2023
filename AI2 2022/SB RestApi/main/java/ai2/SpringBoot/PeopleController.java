package ai2.SpringBoot;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.annotation.Resource;

@Controller
public class PeopleController {
    @Resource(name = "peopleService")
    PeopleService peopleService;


    @Autowired
    public PeopleController(PeopleService peopleService) {
        this.peopleService = peopleService;
    }

    @GetMapping("/")
    public String index(@RequestParam(required = false) Model model, String myParam) {
        model.addAttribute("string", "Napis");
        model.addAttribute("myParam", myParam);
        return "index";
    }

    @GetMapping("/show/{name}")
    public String start(@PathVariable String name, @RequestParam String familyName, Model model) {
        model.addAttribute("name", name);
        model.addAttribute("familyName", familyName);
        return "show";
    }

    @GetMapping("/people")
    public String people(Model model) {
        model.addAttribute("people", peopleService.getPeople());
        return "people";
    }

    @GetMapping("/add")
    public String add(Model model) {
        Person person = new Person("firstName", "lastName");
        model.addAttribute("person", person);
        return "edit";
    }

    @PostMapping("/save")
    public String save(Person person) {
        peopleService.addPerson(person);
        return "redirect:/people";
    }
}
