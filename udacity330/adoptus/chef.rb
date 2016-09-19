service 'httpd' do
  supports :restart => true, :reload => true
  action :enable
end

package 'sqlite' do
  action :install
end

package 'python27-pip' do
  action :install
end

package ' mod_wsgi-python27' do
  action :install
end

execute 'pip install flask'
execute 'pip install sqlalchemy'


