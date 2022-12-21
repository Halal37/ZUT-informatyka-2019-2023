import { Component } from '@angular/core';
import { DateTime } from 'luxon';
import { forkJoin, from, Observable, of } from 'rxjs';
import { Task } from '../models/task';
import { TaskService } from '../task.service';

@Component({
  selector: 'app-tasks',
  templateUrl: './tasks.component.html',
  styleUrls: ['./tasks.component.css']
})
export class TasksComponent {
  activeTasks: Task[] = [];
  newTask: Task = {};
  completedTasks: Task[] = [];

  constructor(
    private taskService: TaskService
  ) {}

  ngOnInit() {
    this.getActivedTasks();
  }

  onAddTaskClick(taskName: string, taskDate: string) {
    const date = DateTime.fromFormat(taskDate, "d.MM.yyyy", {locale: 'pl-PL'}).toJSDate();
    this.newTask = {
      title: taskName,
      deadline: date,
      completed: false,
      archived: false
    }
    this.taskService.postTask(this.newTask).subscribe(() => {
      this.getActivedTasks();
      this.newTask = {};
    });
  }
  switchTaskChanged(task: Task) {
    if (!task.completed) {
      task.completed = true;
      this.completedTasks.push(task);
      return;
    }
    task.completed = false;
    let idx: number = this.completedTasks.indexOf(task);
    this.completedTasks.splice(idx, 1);
  }

  onArchiveClick() {
    let obs: Observable<Task>[] = [];
    this.completedTasks.forEach(task => {
      task.archived = true;
      let res = this.taskService.putTask(task);
      obs.push(res);
    });

    forkJoin(obs).subscribe(res => {
      this.getActivedTasks();
    })
  }

  private getActivedTasks() {
    this.taskService.getTasks(false).subscribe(
      (res) => {
        this.activeTasks = res;
      }
    )
  }
}
