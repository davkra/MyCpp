# MyCpp

Little playground for different C/C++ shenanigans...

- [MyCpp](#mycpp)
  - [bash\_init.sh](#bash_initsh)

## bash_init.sh

Add the working directory to the `PATH`, which allows running programs directly without using `./`.

If you are using VS-Code you can use the following setting in you `settings.json` to run the script, every time you open up the integrated terminal.

```json
"terminal.integrated.profiles.linux": {
    "bash": {
      "path": "bash",
      "icon": "terminal-bash",
      "args": [
        "bash_init.sh"
      ]
    }
  }
```
