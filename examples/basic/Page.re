open PageLocale;

let component = "Page" |> ReasonReact.statelessComponent;

let make = (~locale, ~setLocale, _) => {
  let getClassName = locale' => locale' === locale ? "active" : "";
  let setEnLocale = (_) => Locale.En |> setLocale;
  let setRuLocale = (_) => Locale.Ru |> setLocale;
  let localeToElement = locale =>
    locale |> Locale.mapLocaleToString |> ReasonReact.string;
  {
    ...component,
    render: (_) =>
      <div className="container">
        <div className="buttons">
          <button className=(Locale.En |> getClassName) onClick=setEnLocale>
            (Locale.En |> localeToElement)
          </button>
          <button className=(Locale.Ru |> getClassName) onClick=setRuLocale>
            (Locale.Ru |> localeToElement)
          </button>
        </div>
        <div className="message">
          <ReactIntl.DefinedMessage message=pageLocale##hello />
          (" " |> ReasonReact.string)
          <ReactIntl.DefinedMessage message=pageLocale##world />
        </div>
        <ReactIntl.IntlInjector>
          ...(
               intl =>
                 <div>
                   <ReactIntl.DefinedMessage message=pageLocale##today />
                   (" " |> ReasonReact.string)
                   (Js.Date.make() |> intl.formatDate |> ReasonReact.string)
                   (" (intl.formatDate)" |> ReasonReact.string)
                   <br />
                   <ReactIntl.DefinedMessage message=pageLocale##today />
                   (" " |> ReasonReact.string)
                   <ReactIntl.FormattedDate value=(Js.Date.make()) />
                   (" (FormattedDate)" |> ReasonReact.string)
                 </div>
             )
        </ReactIntl.IntlInjector>
      </div>,
  };
};
