import $$ from 'dom7';
import Framework7 from 'framework7/framework7.esm.bundle.js';

// Import F7 Styles
import 'framework7/css/framework7.bundle.css';

// Import Icons and App Custom Styles
import '../css/icons.css';
import '../css/app.css';
// Import Cordova APIs
import cordovaApp from './cordova-app.js';
// Import Routes
import routes from './routes.js';

var app = new Framework7({
  root: '#app', // App root element
  id: 'io.framework7.myapp', // App bundle ID
  name: 'test', // App name
  theme: 'auto', // Automatic theme detection
  // App root data
  data: function () {
    return {
      user: {
        firstName: 'John',
        lastName: 'Doe',
      },

    };
  },
  // App root methods
  methods: {
    helloWorld: function () {
      app.dialog.alert('Hello World!');
    },
  },
  // App routes
  routes: routes,
  // Enable panel left visibility breakpoint
  panel: {
    leftBreakpoint: 960,
  },


  // Input settings
  input: {
    scrollIntoViewOnFocus: Framework7.device.cordova && !Framework7.device.electron,
    scrollIntoViewCentered: Framework7.device.cordova && !Framework7.device.electron,
  },
  // Cordova Statusbar settings
  statusbar: {
    overlay: Framework7.device.cordova && Framework7.device.ios || 'auto',
    iosOverlaysWebView: true,
    androidOverlaysWebView: false,
  },
  on: {
    init: function () {
      var f7 = this;
      if (f7.device.cordova) {
        // Init cordova APIs (see cordova-app.js)
        cordovaApp.init(f7);
      }
    },
  },
});

// Login Screen Demo
$$('#my-login-screen .login-button').on('click', function () {
  var username = $$('#my-login-screen [name="username"]').val();
  var password = $$('#my-login-screen [name="password"]').val();

  // Close login screen
  app.loginScreen.close('#my-login-screen');

  // Alert username and password
  app.dialog.alert('Username: ' + username + '<br>Password: ' + password);
});

$$(document).on("page:init",'.page[data-name="about"]',function(e){
  $$('#dodawanie_przycisk').on('click', () => {      
    console.log("KLIK")
    pesel_function();
  });


});


function pesel_function(){
  var dodawanie_pola_1=document.getElementById("pesel").value;
  var s = document.getElementById(pesel);

      if (SetError(length != 11))
        return;
  
      var aInt = new Array();
      for (i=0;i<11; i++)
      {
        aInt[i] = parseInt(s.substring(i,i+1));
        if (isNaN(aInt[i]))
        {
          SetError(1);
          return;
        }
      }
  
      var wagi = [1,3,7,9,1,3,7,9,1,3,1];
      var sum=0;
      for (i=0;i<11;i++)
        sum+=wagi[i]*aInt[i];
      if (SetError((sum%10)!=0))
        return;
  
      var rok = 1900+aInt[0]*10+aInt[1];
      if (aInt[2]>=2 && aInt[2]<8)
        rok+=Math.floor(aInt[2]/2)*100;
      if (aInt[2]>=8)
        rok-=100;
  
      var miesiac = (aInt[2]%2)*10+aInt[3];
      var dzien = aInt[4]*10+aInt[5];
  
      if (SetError(!checkDate(dzien,miesiac,rok)))
        return;
      var plec = (aInt[9]%2==1)?"M":"K";
  
      document.getElementById("rok").value = rok;
      document.getElementById("miesiac").value = miesiac;
      document.getElementById("dzien").value = dzien;
      document.getElementById("plec").value = plec;
    }
    function SetError(c){
      document.getElementById("hasError").style.visibility=(c?"visible":"hidden");
      return c;
    }
    function checkDate(d,m,y)
    {
      var dt = new Date(y,m-1,d);
      return dt.getDate()==d &&
            dt.getMonth()==m-1 &&
            dt.getFullYear()==y;
    }