
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Background message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Background 
{
    /**
     * The location of the `Background` keyword
     */
    public Location Location { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public List<Step> Steps { get; }
    public string Id { get; }


    public Background(
        Location location,
        string keyword,
        string name,
        string description,
        List<Step> steps,
        string id
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "Background.Location cannot be null");
        this.Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Background.Keyword cannot be null");
        this.Name = name ?? throw new ArgumentNullException("Name", "Background.Name cannot be null");
        this.Description = description ?? throw new ArgumentNullException("Description", "Background.Description cannot be null");
        this.Steps = steps ?? throw new ArgumentNullException("Steps", "Background.Steps cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "Background.Id cannot be null");
    }
}
