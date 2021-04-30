
# this script setup virtualenv commands for user to create, delete, list, enter and exit virtual environmnet

[[ $0 != "$BASH_SOURCE" ]] && sourced=1 || sourced=0
if [ "$sourced" = 1 ]
then
  python3 -m pip install virtualenvwrapper --force-reinstall
  export WORKON_HOME=$HOME/.virtualenvs
  source `which virtualenvwrapper.sh`
  echo ""
  echo "virtualenv commands:"
  echo '  *  "mkvirtualenv [env_name]"  -  Create a virtual environment'
  echo '  *  "deactivate"               -  Exit the current virtual environment'
  echo '  *  "workon [env_name]"        -  Enter an existing virtual environment'
  echo '  *  "lsvirtualenv"             -  List all virtual environments'
  echo '  *  "rmvirtualenv [env_name]"  -  Delete a virtual environment'
  echo ""
else
  echo ""
  echo 'You need to source this script for command to work! please run as shown below'
  echo ""
  echo 'source virtualenv.sh'
  echo ""
fi