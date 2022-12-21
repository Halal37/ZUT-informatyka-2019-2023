import { Component } from '@angular/core';
import { Task } from '../models/task';
import { TaskService } from '../task.service';

@Component({
  selector: 'app-archive',
  templateUrl: './archive.component.html',
  styleUrls: ['./archive.component.css']
})
export class ArchiveComponent {
  archivedTasks: Task[] = [];

  constructor(
    private taskService: TaskService
  ) {}

  ngOnInit() {
    this.getArchivedTasks();
  }

  deleteOnClick(task: Task): void {
    this.taskService.deleteArchivedTask(task).subscribe(
      (res) => {
        this.getArchivedTasks();
      }
    );
  }

  private getArchivedTasks() {
    this.taskService.getTasks(true).subscribe(
      (res) => {
        this.archivedTasks = res;
      }
    )
  }
}
