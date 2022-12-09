import {Component, Input, OnChanges} from '@angular/core';
import {RandomService} from "../random.service";

@Component({
  selector: 'app-random',
  templateUrl: './random.component.html',
  styleUrls: ['./random.component.css']
})
export class RandomComponent implements OnChanges {

  myNumber: number;
  check: string;
  color: string;
  limitNumber: number;
  @Input() inputNumber: any;

  constructor(private randomService: RandomService) {
    this.limitNumber = 10;
    this.color = "black";
    this.myNumber = this.buttonClick();
    this.check = "Przed sprawdzeniem";
  }

  ngOnChanges(): void {
  }

  importLimit(number: number){
    this.limitNumber= number;
  }

  buttonClick(): number {
    this.myNumber = this.randomService.randomNumber(this.limitNumber);
    return this.myNumber;
  }

  halfCheck(): void {

    if (this.myNumber <= this.limitNumber * 0.5) {
      this.check = "Dolna połowa wartości";
      this.color = "green"

    } else {
      this.check = "Górna połowa wartości";
      this.color = "red"
    }
  }

}
