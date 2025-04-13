### Git Commands

#### Basic Commands
- `git init` - Initialize a new Git repository.
- `git clone <repository-url>` - Clone an existing repository.
- `git status` - Check the status of your working directory and staging area.
- `git add <file>` - Stage changes for commit.
- **`git add .` - Stage all changes in the current directory.**
- **`git commit -m "message"` - Commit staged changes with a message.**
- `git log` - View the commit history.

#### Branching and Merging
- **`git branch -a` - List all branches in the repository.**
- **`git branch <branch-name>` - Create a new branch.**
- **`git checkout <branch-name>` - Switch to a specific branch.**
- `git checkout -b <branch-name>` - Create and switch to a new branch.
- `git merge <branch-name>` - Merge a branch into the current branch.

#### Remote Repositories
- `git remote add origin <repository-url>` - Link a local repository to a remote one.
- **`git push -u origin <branch-name>` - Push changes to a remote branch.**
- `git pull origin <branch-name>` - Pull changes from a remote branch.
- `git fetch` - Fetch changes from the remote repository without merging.

#### Undoing Changes
- `git reset <file>` - Unstage a file.
- `git reset --hard` - Reset the working directory and staging area to the last commit.
- `git revert <commit-hash>` - Revert a specific commit.
- `git stash` - Temporarily save changes without committing.
- `git stash pop` - Reapply stashed changes.

#### Advanced Commands
- `git rebase <branch-name>` - Reapply commits on top of another branch.
- `git cherry-pick <commit-hash>` - Apply a specific commit to the current branch.
- `git tag <tag-name>` - Create a tag for a specific commit.
- `git diff` - Show changes between commits, branches, or the working directory.

#### Collaboration
- `git pull --rebase` - Pull changes and reapply your commits on top of them.
- `git push --force` - Force push changes (use with caution).
- `git blame <file>` - Show who made changes to each line of a file.
- `git log --oneline` - View a simplified commit history.

#### Cleanup
- `git clean -f` - Remove untracked files.
- `git gc` - Optimize the repository by cleaning up unnecessary files.

