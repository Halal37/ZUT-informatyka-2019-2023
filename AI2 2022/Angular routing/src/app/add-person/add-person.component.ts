import {Component, OnInit, Input} from '@angular/core';
import {Person, PersonService} from "../person.service";
import { Router} from "@angular/router";

@Component({
  selector: 'app-add-person',
  templateUrl: './add-person.component.html',
  styleUrls: ['./add-person.component.css']
})
export class AddPersonComponent implements OnInit {

  @Input() firstName: string = '';
  @Input() familyName: string = '';
  @Input() age: string = '';
  @Input() city: string = '';
  @Input() street: string = '';
  @Input() postCode: string = '';

  person: Person = {
    address: {}
  };

  constructor(
    private personService: PersonService,
    private router: Router
  ) {

  }

  ngOnInit() {
  }

  onAddClick(): void {
    this.person = {
      firstName: this.firstName,
      familyName: this.familyName,
      age: Number(this.age),
      address: {
        city: this.city,
        street: this.street,
        postCode: this.postCode
      }
    };
    this.personService.addPersonToLocalStorage(this.person);
    this.redirectToHome();
  }

  private redirectToHome() {
    this.router.navigate(['']);
  }
}
