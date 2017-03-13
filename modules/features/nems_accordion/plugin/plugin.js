/**
 * @file
 * Ckeditor plugin file.
 */

(function ($) {
  CKEDITOR.plugins.add('nems_accordion_plugin', {
    init: function (editor) {
      // Utility functions.
      function nemsWrapper(el) {
        if (el.getAttribute) {
          return el.getAttribute('class') == 'accordion';
        }
      };
      function nemsPane(el) {
        if (el.getAttribute) {
          return el.getAttribute('class') == 'accordion-content';
        }
      };

      // Add single button.
      editor.ui.addButton('nems_accordion_plugin_button', {
        label: 'Insert an Accordion',
        command: 'nemsAddAccordion',
        icon: this.path + 'images/button.png'
      });

      // Add CSS for edition state.
      var cssPath = this.path + 'accordion.css';
      editor.on('mode', function () {
        if (editor.mode === 'wysiwyg') {
          this.document.appendStyleSheet(cssPath);
        }
      });

      // Prevent nesting by disabling button.
      editor.on('selectionChange', function (evt) {
        if (editor.readOnly) {
          return;
        }
        var command = editor.getCommand('nemsAddAccordion');
        var element = evt.data.path.lastElement && evt.data.path.lastElement.getAscendant(nemsWrapper, true);
        if (element) {
          command.setState(CKEDITOR.TRISTATE_DISABLED);
        }
        else {
          command.setState(CKEDITOR.TRISTATE_OFF);
        }
      });

      var allowedContent = 'div h3 p(!accordion)';

      editor.addCommand('nemsAddAccordion', {
        allowedContent: allowedContent,

        exec : function (editor) {
          // Create the wrapper div.
          var wrapper = new CKEDITOR.dom.element.createFromHtml('<div class="accordion"><h3>Accordion title</h3><div class="accordion-content"><p>New accordion content</p></div></div>');

          editor.insertElement(wrapper);
        }
      });
      editor.addCommand('nemsAccordionTabBefore', {
        allowedContent: allowedContent,

        exec: function (editor) {
          var element = editor.getSelection().getStartElement();
          var newHeader = new CKEDITOR.dom.element.createFromHtml('<h3>New accordion title</h3>');
          var newContent = new CKEDITOR.dom.element.createFromHtml('<div class="accordion-content"><p>New accordion content</p></div>');
          if (element.getAscendant(nemsPane, true)) {
            element = element.getAscendant(nemsPane, true).getPrevious();
          }
          else {
            element = element.getAscendant('h3', true);
          }
          newHeader.insertBefore(element);
          newContent.insertBefore(element);
        }
      });
      editor.addCommand('nemsAccordionTabAfter', {
        allowedContent: allowedContent,

        exec: function (editor) {
          var element = editor.getSelection().getStartElement();
          var newHeader = new CKEDITOR.dom.element.createFromHtml('<h3>New Accordion title</h3>');
          var newContent = new CKEDITOR.dom.element.createFromHtml('<div class="accordion-content"><p>New accordion content</p></div>');
          if (element.getAscendant('h3', true)) {
            element = element.getAscendant('h3', true).getNext();
          }
          else {
            element = element.getAscendant(nemsPane, true);
          }
          newContent.insertAfter(element);
          newHeader.insertAfter(element);
        }
      });
      editor.addCommand('nemsRemoveAccordionTab', {
        exec: function (editor) {
          var element = editor.getSelection().getStartElement();
          var a;
          if (element.getAscendant('h3', true)) {
            a = element.getAscendant('h3', true);
            a.getNext().remove();
            a.remove();
          }
          else {
            a = element.getAscendant(nemsPane, true);
            if (a) {
              a.getPrevious().remove();
              a.remove();
            }
            else {
              element.remove();
            }
          }
        }
      });

      // Context menu.
      if (editor.contextMenu) {
        editor.addMenuGroup('nemsAccordionGroup');
        editor.addMenuItem('nemsAccordionTabBefore', {
          label: Drupal.t('Add accordion tab before'),
          icon: this.path + 'images/button.png',
          command: 'nemsAccordionTabBefore',
          group: 'nemsAccordionGroup'
        });
        editor.addMenuItem('nemsAccordionTabAfter', {
          label: Drupal.t('Add accordion tab after'),
          icon: this.path + 'images/button.png',
          command: 'nemsAccordionTabAfter',
          group: 'nemsAccordionGroup'
        });
        editor.addMenuItem('nemsRemoveAccordionTab', {
          label: Drupal.t('Remove accordion tab'),
          icon: this.path + 'images/button.png',
          command: 'nemsRemoveAccordionTab',
          group: 'nemsAccordionGroup'
        });

        editor.contextMenu.addListener(function (element) {
          var parentEl = element.getAscendant(nemsWrapper, true);
          if (parentEl) {
            return {
              nemsAccordionTabBefore: CKEDITOR.TRISTATE_OFF,
              nemsAccordionTabAfter: CKEDITOR.TRISTATE_OFF,
              nemsRemoveAccordionTab: CKEDITOR.TRISTATE_OFF
            };
          }
        });
      }
    }
  });
})(jQuery);
