## NEMS Platform Instructions

This documentation assumes that you have a clean version of the subsite starterkit,
checked out from your project repo.
You should not have built the project just yet at this point!

### 1. Fork your project repository  
  
Typically this will look something like ec-europa/myproject-reference. This means that your project will always be in the organisation ec-europa and it will always ends with -reference.  
  

### 2. Clone the forked repository  

Open your terminal and clone this repository to your local machine.  

`git clone https://github.com/my-username/myproject-reference.git`  

### 3. Modify the composer.json file

#### 3.1 Require the ec-europa/nems-platform like so
`
    "ec-europa/nems-platform": "1.*"
`

#### 3.2 Add the package like so`(don't forget the comma after the last package)
```
    {
      "type": "package",
      "package": {
        "name": "ec-europa/nems-platform",
        "version": "1.0",
        "source": {
          "url": "https://github.com/ec-europa/nems-platform-reference.git",
          "type": "git",
          "reference": "master"
        }
      }
    }
```

#### 3.3 Add the post-install-cmd
Modify
```
    "scripts": {
    "post-install-cmd": "resources/scripts/composer/post-install.sh"
    },
```
To
```
    "scripts": {
    "post-install-cmd": ["resources/scripts/composer/post-install.sh","vendor/ec-europa/nems-platform/post-install.sh"]
    },
```

**Make sure that you have correct write permissions setup on your local machine!**  

### 4. Run composer install  

Install all the necessary dependencies for your project. 

**Attention! in case you encounter this error:**
 ```
 sh: 1: vendor/ec-europa/nems-platform/post-install.sh: not found
 Script vendor/ec-europa/nems-platform/post-install.sh handling the post-install-cmd event returned with error code 127
 ```
this is due to the composer.lock file in the starter kit, you can manually require the package like so:

`composer require "ec-europa/nems-platform:1.*"`
### 5. Run post install shell scripts  

Run this command in your terminal:   
  
  `composer run-script post-install-cmd`  
  
### 6. Create site.make file  

In the resources folder you can find site.make.example. Rename this file into site.make and add the following line:  

`includes[] = nems-platform.make`  

### 7. Create a build.properties file

Create a new file called `build.properties` in the root folder and put
properties in it that are unique to your project. You can copy any of the
properties of the `build.properties.dist` file to override them and then commit
the file. The settings will then take effect for all developers that work on the
project.

Some typical project specific settings are the site name, the install profile,
the modules to enable after installation, paths to ignore during coding
standards checks, the version of the platform to use etc.

Example file:

```
# The site name.
subsite.name = My Project

# The install profile to use.
platform.profile.name = multisite_drupal_standard

# The branch, tag or commit to use, eg. 'master', 'develop', '1.7', '7df0d254b'.
# It is possible to use MySQL style wildcards here.
platform.package.reference = master

# Modules to enable after installation. Separate multiple modules with spaces.
# This will typically be the 'mother feature' which will contain all your other
# features and modules as dependencies.
subsite.install.modules = myproject_core
```  

### 8. Create a build.properties.local file

This file contains the configuration which is unique to your local environment,
i.e. your development machine. In here you specify your database credentials,
your base URL, the administrator password etc.

Some other things that can be useful is to provide a list of your favourite
development modules to enable, and whether you want to see verbose output of
drush commands and tests. Another good trick is that you can try out your
project against different versions of the Multisite / NextEuropa platform, for
example you might want to check out if your code still runs fine on the latest
development version by setting `platform.package.reference` to `develop`.

> Because these settings are personal they should not be shared with the rest of
> the team. *Make sure you never commit this file!*

Example `build.properties.local` file:

```
# Database settings.
drupal.db.name = my_project
drupal.db.user = root
drupal.db.password = hunter2

# Admin user.
drupal.admin.username = admin
drupal.admin.password = admin

# Development / testing modules to download.
development.modules.download = coffee devel maillog

# Development / testing modules to enable.
drupal.development.modules = coffee devel field_ui maillog simpletest views_ui

# The base URL to use in Behat tests.
behat.base_url = http://myproject.local/

# The location of the Composer executable.
composer.bin = /etc/bin/composer

# Verbosity of drush commands. Set to TRUE to be verbose.
drush.verbose = FALSE

# Verbosity of PHP Codesniffer. Set to 0 for standard output, 1 for progress
# report, 2 for debugging info.
phpcs.verbose = 2

# Set verbosity for Behat tests. 0 is completely silent, 1 is normal output, 2
# shows exception backtraces, 3 shows debugging information.
behat.options.verbosity = 3
```

### 9. Build your local development environment

Now that our configuration is ready, we can start downloading everything we need
to build our Drupal site.

```
$ ./bin/phing build-dev
```

This will:

* Download the latest validated version of the platform of the branch you
  specified.
* Build the project into the `platform/` subfolder.
* Symlink your custom modules and themes into the platform. This allows you to
  work inside the Drupal site, and still commit your files easily.
* Run `composer install` in the Subsite development directory
  (typically `platform/sites/all`).

> Go get some coffee. The first time you build the site this can take a very
> long time. Future builds will be quicker since the platform will be cached and
> does not have to be downloaded every time.

### 10. Install the site

```
$ ./bin/phing install-dev
```

This will:

* Install the website with `drush site-install`.
* Enable the modules you specified in the `drupal.development.modules` property.

After a few minutes this process should complete and the website should be up
and running!  

You can now browse to your site on http://yourhostname/platform  

> Simply do not forget the /platform at the end!  


### 11. Enable the NEMS features you need for your project  

Make sure to enable all the NEMS features you need for your project. Please follow this order for enabling: 
  
   
1. nems_core  
2. nems_ multilingual_setup  
3. nems_accordion  
4. nems_ call_ for_externals  
5. nems_ call_ for_proposals  
6. nems_ call_ for_tenders  
7. nems_ common_page  
8. nems_ dynamic_submenu  
9. nems_events  
10. nems_gallery  
11. nems_links  
12. nems_news  
13. nems_ press_releases  
14. nems_publications 
15. nems_slider  
16. nems_vacancy  
17. nems_ video_gallery 

## When in need of support  

> You can contact the next-europa maintenance team by creating a jira ticket. We will be glad to help you out!  






