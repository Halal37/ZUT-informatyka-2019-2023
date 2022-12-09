import {Injectable, OnInit} from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class RandomService implements OnInit {

  ngOnInit(): void {
  }

  constructor() {
  }

  public randomNumber(value: number): number {
    return Math.floor(Math.random() * (value - 1) + 1);

  }
}
