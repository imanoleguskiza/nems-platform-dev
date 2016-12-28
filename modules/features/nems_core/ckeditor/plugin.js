/**
 * @file
 * CKEDITOR plugin file.
 */

(function($) {
  // Utility class.
  Drupal.nems_core_ckeditor = Drupal.nems_core_ckeditor || {};
  Drupal.nems_core_ckeditor.filter = {

    /**
     * Regular expressions matching tokens exposed by NextEuropa Token module.
     */
    regex: {
      parse_token: /(file\:\d*\:url)/,
      parse_placeholder: /<nemscore.*token="(.*?)".*>(.*)<\/nemscore>/,
      get_tokens: /\[file:[0-9]:url\]/g,
      get_placeholders: /<nemscore.*?<\/nemscore>/g
    },

    /**
     * Get HTML placeholder give a token and a label.
     *
     * @param token
     *    Token string, followed by its label enclosed in curly brackets.
     *    For example: [node:1:view-mode:full]{Title}.
     *
     * @returns {string}
     */
    getPlaceholderFromToken: function(token) {
      var matches = token.match(this.regex.parse_token);
      return (matches) ? '<nexteuropatoken contenteditable="false" token="' + matches[1] + '"></nexteuropatoken>' : '';
    },

    /**
     * Get token given an HTML placeholder.
     *
     * @param placeholder
     *    Placeholder string.
     *
     * @returns {string}
     */
    getTokenFromPlaceholder: function(placeholder) {
      var matches = placeholder.match(this.regex.parse_placeholder);
      return (matches) ? '[' + matches[1] + ']{' + matches[2] + '}' : '';
    },

    /**
     * Replaces tokens with placeholders.
     *
     * @param content
     *    Text coming from WYSIWYG.
     *
     * @returns {string}
     */
    replaceTokenWithPlaceholder: function(content) {
      var matches = content.match(this.regex.get_tokens);
      if (matches) {
        for (var i = 0; i < matches.length; i++) {
          content = content.replace(matches[i], this.getPlaceholderFromToken(matches[i]));
        }
      }
      return content;
    },

    /**
     * Replaces placeholders with tokens.
     *
     * @param content
     */
    replacePlaceholderWithToken: function(content) {
      console.log('replacePlaceholderWithToken');
      var matches = content.match(this.regex.get_placeholders);
      if (matches) {
        for (var i = 0; i < matches.length; i++) {
          content = content.replace(matches[i], this.getTokenFromPlaceholder(matches[i]));
        }
      }
      return content;
    }
  };
  
  /**
   * Register the plugin with WYSIWYG.
   */
  Drupal.wysiwyg.plugins.nems_core_ckeditor = {
    /**
    * Attach function, called when a rich text editor loads.
    * This finds all [tags] and replaces them with the html
    * that needs to show in the editor.
    *
    * This finds all JSON macros and replaces them with the HTML placeholder
    * that will show in the editor.
    */
   attach: function (content, settings, instanceId) {
     content = Drupal.nems_core_ckeditor.filter.replaceTokenWithPlaceholder(content);
     return content;
   },
   
   /**
    * Detach function, called when a rich text editor detaches
    */
   detach: function (content, settings, instanceId) {
     content = Drupal.nems_core_ckeditor.filter.replacePlaceholderWithToken(content);
     return content;
   }
  }
  
  CKEDITOR.plugins.add('nems_core_ckeditor', {
    init: function(editor) {
      // Define DTD rules for placeholder tag "nemscore".
      CKEDITOR.dtd['nemscore'] = CKEDITOR.dtd;
      CKEDITOR.dtd.$blockLimit['nemscore'] = true;
      CKEDITOR.dtd.$inline['nemscore'] = true;
      CKEDITOR.dtd.$nonEditable['nemscore'] = true;
      if (parseFloat(CKEDITOR.version) >= 4.1) {
        // Register allowed tag for advanced filtering.
        editor.filter.allow('nemscore[!*]', 'nemscore', true);
        // Objects should be selected as a whole in the editor.
        CKEDITOR.dtd.$object['nemscore'] = true;
      }

      // Ensure tokens instead the html element is saved.
      editor.on('setData', function(event) {
        var content = event.data.dataValue;
        event.data.dataValue = Drupal.nems_core_ckeditor.filter.replaceTokenWithPlaceholder(content);
      });

      // Replace tokens with WYSIWYG placeholders.
      editor.on('getData', function(event) {
        var content = event.data.dataValue;
        event.data.dataValue = Drupal.nems_core_ckeditor.filter.replacePlaceholderWithToken(content);
      });
    }
  });

})(jQuery);
