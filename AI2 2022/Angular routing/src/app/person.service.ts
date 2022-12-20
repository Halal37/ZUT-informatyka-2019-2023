import { Injectable} from '@angular/core';

@Injectable({
  providedIn: 'root'
})




export class PersonService{
  constructor() { }

  private saveLocalStorageState(localStoragePersonDataState: Person[]) {
    localStorage.setItem('person-data', JSON.stringify(localStoragePersonDataState));
  }

  getPeopleFromLocalStorage(): [] {
    return JSON.parse(localStorage.getItem('person-data') || '[]')
  }

  addPersonToLocalStorage(person: Person) {
    let peopleInLocalStorage: Person[] = this.getPeopleFromLocalStorage();
    peopleInLocalStorage.push(person);
    this.saveLocalStorageState(peopleInLocalStorage);
  }

  deletePersonFromLocalStorage(idx: number) {
    let peopleInLocalStorage: Person[] = this.getPeopleFromLocalStorage();
    peopleInLocalStorage.splice(idx, 1);
    this.saveLocalStorageState(peopleInLocalStorage);
  }

  getPersonFromLocalStorage(idx: number): Person {
    return JSON.parse(localStorage.getItem('person-data') || '[]')[idx];
  }
}
export interface Person {
  firstName?: string;
  familyName?: string;
  age?: number;
  address: {
    city?: string;
    street?: string;
    postCode?: string;
  }
}

