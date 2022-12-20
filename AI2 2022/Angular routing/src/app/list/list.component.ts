import {Component, OnInit} from '@angular/core';
import {ActivatedRoute, Router} from "@angular/router";
import {Person} from "../person.service";
import { PersonService } from '../person.service';

@Component({
  selector: 'app-list',
  templateUrl: './list.component.html',
  styleUrls: ['./list.component.css']
})
export class ListComponent implements OnInit{
  people: Person[] = [];

  constructor(
    private route:ActivatedRoute,
    private router: Router,
    private personService: PersonService
) {}

  ngOnInit() {
    console.log(localStorage)
    this.people = this.personService.getPeopleFromLocalStorage();
  }
  public goAdd(){
    this.router.navigate(['add']).then(() => {
      window.location.reload();
    });
  }
  deletePersonFromList(idx: number) {
    this.personService.deletePersonFromLocalStorage(idx);
    this.people = this.personService.getPeopleFromLocalStorage();
  }
}
